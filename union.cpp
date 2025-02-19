#include <iostream>
using namespace std;

union MyUnion {
    int i;
    float f;
    char c;
};

int main() {
    MyUnion u;
    u.i = 42;     // تخزين قيمة في int
    cout << "i: " << u.i << endl;

    u.f = 3.14f;  // تخزين قيمة في float (هذا يمسح قيمة int)
    cout << "f: " << u.f << endl;

    cout << "i (after f): " << u.i << endl;  // ستظهر قيمة غير معروفة لأن الذاكرة تم الكتابة عليها
    return 0;
}



#include <iostream>
using namespace std;

union MyUnion {
    int i;
    float f;
    char c;
};

int main() {
    MyUnion u;
    u.i = 42;     // تخزين قيمة في int
    cout << "i: " << u.i << endl;

    u.f = 3.14f;  // تخزين قيمة في float (هذا يمسح قيمة int)
    cout << "f: " << u.f << endl;

    cout << "i (after f): " << u.i << endl;  // ستظهر قيمة غير معروفة لأن الذاكرة تم الكتابة عليها
    return 0;
}