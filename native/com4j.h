#pragma once
#include "cleanup.h"
#include "java_id.h"

const int BYREF = 0x8000;

// see com4j.NativeType
enum Conv {
	cvBSTR = 1,
	cvBSTR_byRef = 1|BYREF,
	cvLPCWSTR = 2,
	cvLPCSTR = 3,


	cvINT8 = 100,
	cvINT16 = 101,
	cvINT32 = 102,

	cvHRESULT = 200,
};


typedef void (*ComMethod)();
typedef ComMethod* VTable;



class Environment {
	// JNI environment
	JNIEnv* const		env;
	// post actions
	PostAction* postActions;
public:
	Environment( JNIEnv* _env ) : env(_env) {
		postActions = NULL;
	}
	~Environment();

	// invoke a method
	jobject invoke(
		void* pComObject,		// pointer to the the COM object
		ComMethod		method,	// pointer to the method to invoke
		jobjectArray	args,	// arguments
		jint*			convs,	// conversions
		jclass			retType,
		int				retIndex,
		bool			retIsInOut,
		jint			retConv
	);

	// adds a new post action
	void add( PostAction* cu );

	// get the char array from jstring and schedule a clean up
	const jchar* toChars( jstring s );

	// get the \0-terminated wide string
	const wchar_t* toLPCWSTR( jstring s );

	// get the \0-terminated string
	LPCSTR toLPCSTR( jstring s );

	BSTR toBSTR( jstring s );
};

// reference to java.lang.Number
extern JClassID javaLangNumber;
// reference to org.kohsuke.com4j.comexception
extern JClassID comexception;



struct MyGUID {
	INT64 l1;
	INT64 l2;
public:
	MyGUID( INT64 v1, INT64 v2 ) {
		l1=v1; l2=v2;
	}

	operator const GUID&() const { return *reinterpret_cast<const GUID*>(this); }
};


