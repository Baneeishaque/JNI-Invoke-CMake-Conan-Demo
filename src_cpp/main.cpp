#include <iostream>
#include <jni.h>

JNIEnv *create_vm(JavaVM **jvm) {

    printf("creating vm");
    JNIEnv *env;

    JavaVMInitArgs vm_args;

    JavaVMOption options;
    //Path to the java source code
    options.optionString = (char*) "-Djava.class.path=../src_java_lib/out/production/src_java_lib";

    //JDK version
    vm_args.version = JNI_VERSION_10;
    vm_args.nOptions = 1;
    vm_args.options = &options;
    vm_args.ignoreUnrecognized = JNI_FALSE;

    int ret = JNI_CreateJavaVM(jvm, (void **) &env, &vm_args);
    if (ret < 0)
        printf("\nUnable to Launch JVM\n");
    return env;
}

int main() {

    printf("hai");
    JNIEnv *env;
    JavaVM *jvm;
    env = create_vm(&jvm);
    if (env == NULL) {
        printf("not ok");
        return 1;
    }
    printf("ok");
    return 0;
}
