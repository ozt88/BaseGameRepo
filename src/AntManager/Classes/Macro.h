
#define SAFE_DELETE(PTR)\
{\
	if (PTR != nullptr)\
			{\
		delete PTR; \
		PTR = nullptr; \
			}\
}

#define SAFE_RELEASE(PTR)\
{\
if (PTR != nullptr)\
	{\
	PTR->release(); \
	PTR = nullptr; \
	}\
}