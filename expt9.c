#include"inftopost.h"
#include"codegen.h"
void main() {
    char* post_str = postfix();
    struct ElementBox* elementbox;
    elementbox=threeAddCode(post_str);
    codeGen(elementbox);
}