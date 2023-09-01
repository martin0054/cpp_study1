#include "header.h"

int main(int argc, char* argv[]) {


    std::cout << "test" << std::endl;


    std::vector<int> num;


    // 시드값을 얻기 위한 random_device 생성.
    std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 gen(rd());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> dis(0, 99);


    for (int i = 0; i < 10; i++) { 
        auto randomNum = dis(gen);
        std::cout << "난수 : " << randomNum << std::endl;

        num.push_back(randomNum);

    }

    //정렬
    sort(num.begin(), num.end());


    // 기본 for문 사용 지양 
    // cbegin & begin 차이 = > const_iterator / iterator 
    // => const_iterator : 값 수정 불가  


    auto print = [](const int& n) { std::cout << n << ' '; }; //람다 exprssion

    std::for_each(num.cbegin(), num.cend(), print);
    std::cout << std::endl;

    for (const auto& val : num) std::cout << val << " ";
    std::cout << std::endl;
      
    return 0;
}
