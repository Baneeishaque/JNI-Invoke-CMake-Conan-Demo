#include <iostream>
#include <jni.h>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

typedef jint(JNICALL *CreateJavaVM)(JavaVM **, void **, void *);

void createJVM(JavaVM *&jvm, JNIEnv *&env);
void loadJvmDll(CreateJavaVM *createJavaVM);

// JNIEnv *create_vm(JavaVM **jvm) {

//     printf("creating vm");
//     JNIEnv *env;

//     JavaVMInitArgs vm_args;

//     JavaVMOption options;
//     //Path to the java source code
//     options.optionString = (char*) "-Djava.class.path=../src_java_lib/out/production/src_java_lib";

//     //JDK version
//     vm_args.version = JNI_VERSION_10;
//     vm_args.nOptions = 1;
//     vm_args.options = &options;
//     vm_args.ignoreUnrecognized = JNI_FALSE;

//     int ret = JNI_CreateJavaVM(jvm, (void **) &env, &vm_args);
//     if (ret < 0)
//         printf("\nUnable to Launch JVM\n");
//     return env;
// }

int main() {

    // JNIEnv *env;
    // JavaVM *jvm;
    // env = create_vm(&jvm);
    // if (env == NULL) {
    //     return 1;
    // }

    JavaVM *jvm;
    JNIEnv *env;

    createJVM(jvm, env);

    jvm->DestroyJavaVM();
    return 0;
}

void createJVM(JavaVM *&jvm, JNIEnv *&env) {

    cout << "Loading JVM DLL" << endl;
    CreateJavaVM createJavaVM;
    loadJvmDll(&createJavaVM);
    cout << "Creating JVM Instance" << endl;
    // https://docs.oracle.com/javase/10/docs/specs/jni/invocation.html
    JavaVMInitArgs vm_args;
    auto *options = new JavaVMOption[3];
    options[0].optionString = (char *) "-Djava.class.path=";
    options[1].optionString = (char *) "-Djava.library.path=";
    options[2].optionString = (char *) "-verbose:jni";
    vm_args.version = JNI_VERSION_10;
    vm_args.nOptions = 3;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_FALSE;
    cout << "Starting VM..." << endl;
    createJavaVM(&jvm, (void **) &env, &vm_args);
    cout << "VM started" << endl;

    delete[] options;
}

void loadJvmDll(CreateJavaVM *createJavaVM) {

    const char *jvmDLLPath = "jre/bin/server/jvm.dll";
    HINSTANCE jvmDll = LoadLibrary(jvmDLLPath);
    if (jvmDll == nullptr) {
        DWORD lastErrorCode = GetLastError();
        if (lastErrorCode == 126) {
            // "The specified module could not be found."
            // load msvcr100.dll from the bundled JRE, then try again
            std::cout << "Failed to load jvm.dll. Trying to load msvcr100.dll first ..." << std::endl;

            HINSTANCE hinstVCR = LoadLibrary("jre\\bin\\msvcr100.dll");
            if (hinstVCR != nullptr) {
                jvmDll = LoadLibrary(jvmDLLPath);
            }
        }
        printf("Error: %d\n", lastErrorCode);
    }

    *createJavaVM = (CreateJavaVM) GetProcAddress(jvmDll, "JNI_CreateJavaVM");
}
