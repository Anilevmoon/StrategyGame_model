#include <CRX/Base/TXTest.h>

int main() {
	RUN_ALLAUTOTESTS();
	crx::TDebug::TXTest::ShowStats();

	return 0;
}

//#include <Algorithm/TSmartFunction.h>
//#include <iostream>
//
//class TObject1 {
//    public:
//    void FooImplementation() {
//        std::cout << "TObject1::Foo()\n";
//    }
//
//    public:
//    TSmartFunction<void()> Foo = TSmartFunction<void()>(this, &TObject1::FooImplementation);
//};
//
//class TObject1Preview {
//    public:
//    void UpdatePreviewImplementation() {
//        std::cout << "TObject1Preview::UpdatePreview()\n";
//    }
//
//    public:
//    TSmartFunction<void()> UpdatePreview{this, &TObject1Preview::UpdatePreviewImplementation};
//};
//
//void Boo() {
//    std::cout << "Boo()\n";
//}
//
//struct TNetAction {
//    void Send() {
//        std::cout << "TNetAction::Send()\n";
//    }
//};
//
//int main() {
//    TObject1 obj;
//    obj.Foo.Bind(&Boo);
//
//    std::function<void()> handler = [] { std::cout << "function()\n"; };
//    obj.Foo.Bind(nullptr, handler);
//
//    TObject1Preview preview;
//    obj.Foo.Bind(&preview, &TObject1Preview::UpdatePreviewImplementation);
//
//    obj.Foo();
//
//    std::cout << "\nUnBind: &Boo, &preview:\n";
//
//    obj.Foo.UnBind(&Boo);
//
//    obj.Foo.Bind(nullptr, [] { std::cout << "lambda()\n"; });
//    obj.Foo.UnBind(&preview, &TObject1Preview::UpdatePreviewImplementation);
//
//    obj.Foo();
//
//    std::cout << "\nUnBind: nullptr:\n";
//
//    obj.Foo.UnBind(nullptr);
//    obj.Foo();
//
//    std::cout << "\nBind: EventUpdatePreview:\n";
//
//    TNetAction net;
//    std::function<void(TNetAction*)> action = &TNetAction::Send;
//
//    preview.UpdatePreview.Bind(&net, action);
//    obj.Foo.Bind(&preview, preview.UpdatePreview);
//
//    obj.Foo();
//
//    std::cout << "\nUnBind: EventUpdatePreview:\n";
//
//    preview.UpdatePreview.UnBind(&net);
//    obj.Foo();
//
//    return 0;
//}