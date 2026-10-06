#include <iostream>
#include <list>
static void list_example_1(){
    std::list<int> l1{20, 30, 40, 50, 60,70, 80};
    print_container("l1 (initial values:", l1);
    std::cout <<"l1.size()"<< l1.size() << std::endl;
    std::cout <<"l1.size()"<< l1.front() << std::endl;
    std::cout <<"l1.size()"<< l1.back() << std::endl;
    std::cout <<"l1.size()"<< l1.size() << std::endl;
    std::cout <<"l1.size()"<< l1.front() << std::endl;
    std::cout <<"l1.size()"<< l1.back() << std::endl;

    // push_back, push_front
    l1.push_back(10);
    l1.push_back(90);
    print_container("l1 (after push)", l1);
    std::cout <<"l1.size()"<< l1.size() << std::endl;
    std::cout <<"l1.size()"<< l1.front() << std::endl;
    std::cout <<"l1.size()"<< l1.back() << std::endl;

    // std::advance
    

}
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}