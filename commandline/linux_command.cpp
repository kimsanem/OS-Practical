#include <iostream>
#include <cstdlib> // for system()
using namespace std;

int main() {
    // Information Maintenance commands
    cout << "\n--- Information Maintenance Commands ---\n";
    system("echo 'Word count:' && wc image.png");
    system("clear"); // This will clear the screen
    system("echo 'Calendar:' && cal");
    system("echo 'Logged in users:' && who");
    system("echo 'Current date:' && date");
    system("echo 'Current directory:' && pwd");

    // File Management commands
    cout << "\n--- File Management Commands ---\n";
    system("echo 'File content:' && cat image.png | head -n 5");
    system("cp image.png image_copy.png && echo 'File copied'");
    system("rm image_copy.png && echo 'File removed'");
    system("mv image.png image_renamed.png && echo 'File renamed'");
    system("mv image_renamed.png image.png"); // rename back
    system("echo 'Comparing files:' && cmp image.png image.png");
    system("echo 'Common lines:' && comm <(echo 'a\nb') <(echo 'a\nc')");
    system("echo 'Differences:' && diff <(echo 'a\nb') <(echo 'a\nc')");
    system("echo 'Finding files:' && find . -name '*.png'");
    system("echo 'Grep search:' && grep 'Practical' image.png");

    // Directory Management commands
    cout << "\n--- Directory Management Commands ---\n";
    system("mkdir test_dir && echo 'Directory created'");
    system("cd test_dir && touch file.txt && cd ..");
    system("ls test_dir");
    system("rmdir test_dir && echo 'Directory removed'");
    
    return 0;
}