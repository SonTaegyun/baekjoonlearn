#include <iostream>
using namespace std;
void print_re(int n,int depth){
    for(int i=0;i<depth;i++)
        std::cout << "____";
    std::cout << "\"����Լ��� ������?\"\n";
    for(int i=0;i<depth;i++)
        std::cout << "____";
    if(n==0)
        std::cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    else{
        std::cout <<"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        for(int i=0;i<depth;i++)
            std::cout << "____";
        std::cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        for(int i=0;i<depth;i++)
            std::cout << "____";
        std::cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
        print_re(n-1,depth+1);
    }
    for(int i=0;i<depth;i++)
        std::cout << "____";
    std::cout << "��� �亯�Ͽ���.\n";
}

int main(){
    int n;
    std::cin >> n;
    std::cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    print_re(n,0);
    return 0;
}