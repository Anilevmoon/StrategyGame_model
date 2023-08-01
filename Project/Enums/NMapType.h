#ifndef NMAP_TYPE_H
#define NMAP_TYPE_H

namespace NNMapType {
	enum NMapType {
		Flat,
		FiveOnFive,
		TenOnTen,
		NoUnits
	};

}
using NMapType = NNMapType::NMapType;

#endif