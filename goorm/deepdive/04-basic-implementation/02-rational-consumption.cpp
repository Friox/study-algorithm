#include <iostream>
#include <map>
using std::string, std::cin, std::cout;

int main() {
    int N, price; // N, 가격 변수 선언
    string name; // 물품 이름 string 변수
    cin >> N; // N 입력

    // map 자료형은 key 기준으로 오름차순 자동정렬
    // 가격 기준으로 가장 비싼 물건과 저렴한 물건을 구해야하니,
    // key로 물품의 가격을 지정.
    std::map<int, string> m;
    while (N--) {
        // N 만큼 반복하며 이름과 가격 입력 후 map에 삽입
        cin >> name >> price;
        m.insert({ price, name });
    }

    // 가장 비싼 물품은 map의 맨 뒤에 있음, 역순시작지점 참조.
    // rbegin, begin은 iterator 반환. 역참조로 키-값 쌍을 가져옴
    std::pair<const int, string> max = *m.rbegin();

    // 가장 저렴한 물품은 map의 맨 앞에 있음, 시작지점 참조.
    std::pair<const int, string> min = *m.begin();

    // 출력 (first: 가격, second: 이름)
    cout << max.second << ' ' << max.first << '\n';
    cout << min.second << ' ' << min.first;
}