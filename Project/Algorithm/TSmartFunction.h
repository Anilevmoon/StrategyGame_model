#ifndef TSMART_FUNCTION_H
#define TSMART_FUNCTION_H

#include <memory>
#include <functional>
#include <list>
#include <any>
#include <type_traits>

#include "WorldComponents/TObject.h"

template <typename>
class TSmartFunction;

template <typename ReturnType, typename... ArgumentTypes>
class TSmartFunction<ReturnType(ArgumentTypes...)> {
    public:
    template <typename HandlerType>
    TSmartFunction(HandlerType funcion) {
        Function(funcion);
    }

    template <class ClassType>
    TSmartFunction(ClassType* outer, ReturnType(ClassType::* funcion)(ArgumentTypes...)) {
        Function(outer, funcion);
    }

    public:
    template <typename HandlerType>
    void Function(HandlerType handler) {
        using FunctionType = TFunction<HandlerType, ReturnType, ArgumentTypes...>;
        m_pFunction = std::make_shared<FunctionType>(handler, handler);
    }

    template <class ClassType>
    void Function(ClassType* outer, ReturnType(ClassType::* handler)(ArgumentTypes...)) {
        using MemberFunctionType = TMemberFunction<ClassType, ReturnType(ClassType::*)(ArgumentTypes...), ReturnType, ArgumentTypes...>;
        m_pFunction = std::make_shared<MemberFunctionType>(outer, handler);
    }

    public:
    template <typename HandlerType>
    void Bind(HandlerType handler) {
        Handlers().push_back(std::make_unique<TFunction<HandlerType, void>>(handler, handler));
    }

    template <typename OuterType, typename HandlerType>
    void Bind(OuterType outer, HandlerType handler) {
        Handlers().push_back(std::make_unique<TFunction<HandlerType, void>>(outer, handler));
    }

    template <class ClassType>
    void Bind(ClassType* outer, void (ClassType::* handler)()) {
        Handlers().push_back(std::make_unique<TMemberFunction<ClassType, void (ClassType::*)(), void>>(outer, handler));
    }

    template <typename ClassType>
    void Bind(ClassType* outer, std::function<void(ClassType*)> handler) {
        using MemberFunctionType = TMemberFunction<ClassType, std::function<void(ClassType*)>, void>;
        Handlers().push_back(std::make_unique<MemberFunctionType>(outer, handler));
    }

    public:
    template <typename OuterType>
    void UnBind(OuterType outer) {
        UnBindIf([&outer](auto& item) {
            return IsEqual<OuterType>(outer, item->Outer());
        });
    }

    template <typename OuterType, typename HandlerType>
    void UnBind(OuterType outer, HandlerType handler) {
        UnBindIf([&outer, &handler](auto& item) {
            return IsEqual<OuterType>(outer, item->Outer()) && IsEqual<HandlerType>(handler, item->Handler());
        });
    }

    public:
    ReturnType operator() (ArgumentTypes... args) {
        if constexpr(std::is_void_v<ReturnType>) {
            m_pFunction->Call(args...);
            for(auto& handler : Handlers()) handler->Call();
        } else {
            auto result = m_pFunction->Call(args...);
            for(auto& handler : Handlers()) handler->Call();
            return result;
        }
    }

    protected:
    template <typename ConditionType>
    void UnBindIf(ConditionType condition) {
        for(auto it = Handlers().begin(); it != Handlers().end(); ) {
            if(condition(*it)) it = Handlers().erase(it);
            else ++it;
        } // for(it)
    }

    protected:
    template <typename ObjectType>
    static bool IsEqual(ObjectType object, std::any other) {
        auto otherPtr = std::any_cast<ObjectType>(&other);
        return otherPtr && *otherPtr == object;
    }

    protected:
    template <typename AltReturnType, typename... AltArgumentTypes>
    class IFunction {
        public:
        virtual ~IFunction() = default;

        public:
        virtual AltReturnType Call(AltArgumentTypes... args) = 0;
        virtual std::any Outer() = 0;
        virtual std::any Handler() = 0;
    };

    template <typename FunctorType, typename AltReturnType, typename... AltArgumentTypes>
    class TFunction : public IFunction<AltReturnType, AltArgumentTypes...> {
        public:
        virtual ~TFunction() = default;

        public:
        TFunction(std::any outer, FunctorType handler) : m_pOuter(outer), m_hHandler(handler) {}

        public:
        virtual AltReturnType Call(AltArgumentTypes... args) override { return m_hHandler(args...); }

        virtual std::any Outer() override { return m_pOuter; }
        virtual std::any Handler() override { return m_hHandler; }

        protected:
        std::any m_pOuter;
        FunctorType m_hHandler;
    };

    template <class ClassType, typename FunctorType, typename AltReturnType, typename... AltArgumentTypes>
    class TMemberFunction : public IFunction<AltReturnType, AltArgumentTypes...> {
        public:
        virtual ~TMemberFunction() = default;

        public:
        TMemberFunction(ClassType* outer, FunctorType handler) : m_pOuter(outer), m_hHandler(handler) {}

        public:
        virtual AltReturnType Call(AltArgumentTypes... args) override {
            return std::invoke(m_hHandler, m_pOuter, args...);
        }

        virtual std::any Outer() override { return m_pOuter; }
        virtual std::any Handler() override { return m_hHandler; }

        protected:
        ClassType* m_pOuter = nullptr;
        FunctorType m_hHandler;
    };

    public:
    using FunctionType = IFunction<ReturnType, ArgumentTypes...>;
    using HandlerContainerType = std::list<std::unique_ptr<IFunction<void>>>;

    public:
    HandlerContainerType& Handlers() { return *m_pHandlers; }

    protected:
    std::shared_ptr<FunctionType> m_pFunction = nullptr;
    std::shared_ptr<HandlerContainerType> m_pHandlers = std::make_shared<HandlerContainerType>();
};

#endif // TSMART_FUNCTION_H