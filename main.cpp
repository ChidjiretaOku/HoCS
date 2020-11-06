#include <vector>
#include <cmath>
//#include <windows.h>
#include "Letter.h"

using namespace std;
vector<Letter> vect = {Letter("А", 1), Letter("Б", 2), Letter("В", 3), Letter("Г", 4), Letter("Д", 5),
                       Letter("Е", 6),
                       Letter("Ё", 7), Letter("Ж", 8), Letter("З", 9), Letter("И", 10), Letter("Й", 11),
                       Letter("К", 12), Letter("Л", 13),
                       Letter("М", 14), Letter("Н", 15), Letter("О", 16), Letter("П", 17), Letter("Р", 18),
                       Letter("С", 19), Letter("Т", 20),
                       Letter("У", 21), Letter("Ф", 22), Letter("Х", 23), Letter("Ц", 24), Letter("Ч", 25),
                       Letter("Ш", 26), Letter("Щ", 27),
                       Letter("Ъ", 28), Letter("Ы", 29), Letter("Ь", 30), Letter("Э", 31), Letter("Ю", 32),
                       Letter("Я", 33)};

int discriminant(int a, int b, int c) {
    return (b * b - 4 * a * c);
}

vector<int> polynomial(vector<float> ans) {
    vector<int> shift;
    float x1 = ans[0];
    float x2 = ans[1];
    shift.push_back(round(pow(x1, 6) + (3 * pow(x1, 5)) + pow(x1, 4) + pow(x1, 3) + (4 * pow(x1, 2)) + (4 * x1) + 5));
    shift.push_back(round(pow(x2, 6) + (3 * pow(x2, 5)) + pow(x2, 4) + pow(x2, 3) + (4 * pow(x2, 2)) + (4 * x2) + 5));
    return shift;
}

vector<float> equation(int a, int b, int c) {
    vector<float> ans;
    if (discriminant(a, b, c) < 0) {
        __throw_logic_error("Bad u");
    } else if (discriminant(a, b, c) == 0) {
        for (int i = 0; i < 2; ++i) {
            ans.push_back((-b + sqrt(discriminant(a, b, c))) / (2 * a));
        }
    } else {
        ans.push_back((-b + sqrt(discriminant(a, b, c))) / (2 * a));
        ans.push_back((-b - sqrt(discriminant(a, b, c))) / (2 * a));
    }
    return ans;
}

void output(vector<string> v) {
    for (const auto &i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {

//    SetConsoleOutputCP(CP_UTF8);
    auto ans = equation(1, 3, 1);
    auto shift = polynomial(ans);

    vector<string> cypher = {"Ц", "Д", "О", "З", "И", "Ф", "К", "Д", "Ц", "Ю"};

    output(cypher);

    for (int i = 0; i < cypher.size(); ++i) {
        string temp = cypher[i];
        for (int j = 0; j < 33; ++j) {
            if (temp == vect[j].getLetter()) {
                for (int k = 0; k < 33; ++k) {
                    if (vect[k].getCode() == (vect[j].getCode() - shift[0])) {
                        string tmp = vect[k].getLetter();
                        cypher[i] = tmp;
                        break;
                    }
                }
                break;
            }
        }
    }

    output(cypher);

    cin.get();

    return 0;
}