#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string, int> Mark;

    Mark["Anas"] = 10;
    Mark["Ali"] = 20;
    Mark["Mohammed"] = 30;

    for (const auto &pair : Mark) {
        cout << pair.first << " = " << pair.second << endl;
    }

    string Name = "Anas";

    if (Mark.find(Name) != Mark.end()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    std::map<std::string, int> Mark;
    Mark["Ali"] = 90; // إضافة أو تعديل قيمة المفتاح "Ali"
    Mark["Sara"] = 85;

    Mark.insert({"Omar", 95});
    Mark.insert(std::make_pair("Lina", 88));

    auto result = Mark.insert({"Sara", 100});
    if (!result.second) {
        std::cout << "المفتاح موجود مسبقًا!\n";
    }

    Mark.emplace("Yousef", 78);

    for (std::map<std::string, int>::iterator it = Mark.begin(); it != Mark.end();
            ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    cout << Mark["Anas"] << endl;  // استخدام الـ key مباشرة



    return 0;
}


#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> studentAges;

    studentAges["Ali"] = 20;
    studentAges["Omar"] = 22;
    studentAges["Sara"] = 19;

    for (auto pair : studentAges) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}