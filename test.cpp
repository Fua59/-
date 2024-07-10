#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
class Person;
typedef std::vector<Person>::iterator iter;
class Person
{
private:
    char name[10]; // 姓名
    int gender; // 性别
    int age; // 年龄
    char phonenumber[15]; // 电话
    char address[30]; // 地址
public:
    Person() {}
    Person(char name_[], int g, int a, char p[], char add[])
    {
        strcpy(name, name_);
        gender = g;
        age = a;
        strcpy(phonenumber, p);
        strcpy(address, add);
    }
    void SetInfo(char name_[], int g, int a, char p[], char add[]) // 修改信息
    {
        strcpy(name, name_);
        gender = g;
        age = a;
        strcpy(phonenumber, p);
        strcpy(address, add);
    }
    void Show()
    {
        printf("%s\t", name);
        if(gender)
            printf("男\t");
        else
            printf("女\t");
        printf("%d\t", age);
        printf("%s\t%s\t\n", phonenumber, address);
    }
    char * Getname()
    {
        return name;
    }
};
class Address
{
private:
    std::vector<Person> v;
public:
    void Init()
    {
        v.clear();
    }
    void Menu()
    {
        printf("************************\n");
        printf("***** 1.添加联系人 *****\n");
        printf("***** 2.显示联系人 *****\n");
        printf("***** 3.删除联系人 *****\n");
        printf("***** 4.查找联系人 *****\n");
        printf("***** 5.修改联系人 *****\n");
        printf("***** 6.清空联系人 *****\n");
        printf("***** 0.退出通讯录 *****\n");
        printf("************************\n");
    }
    void Add()
    {
        char na[10]; 
        int g, a; 
        char p[15]; 
        char add[30];
        printf("请输入姓名：\n");
        scanf("%s", na);
        printf("请输入性别:(女:0 男:1)\n");
        scanf("%d", &g);
        printf("请输入年龄：\n");
        scanf("%d", &a);
        printf("请输入电话：\n");
        scanf("%s", p);
        printf("请输入地址：\n");
        scanf("%s", add);
        v.push_back(Person(na, g, a, p, add));
        printf("已添加完毕\n");
    }
    int Find(char name_[])
    {
        for(int i = 0; i < v.size(); i++)
        {
            char *name = v[i].Getname();
            if(strcmp(name, name_) == 0)
                return i;
        }
        return -1;
    }
    void Show()
    {
        printf("姓名\t性别\t年龄\t电话         \t地址\t\n");
        for(int i = 0; i < v.size(); i++)
            v[i].Show();
    }
    void Del()
    {
        char name_[10];
        printf("请输入姓名:\n");
        scanf("%s", name_);
        int res = Find(name_);
        if(res != -1)
        {
            v.erase(v.begin() + res);
            printf("删除完毕\n");
        }
        else
            printf("查无此人\n");
    }
    void Search()
    {
        char name_[10];
        printf("请输入姓名:\n");
        scanf("%s", name_);
        int idx = Find(name_);
        if(idx != -1)
            v[idx].Show();
        else
            printf("查无此人\n");
    }
    void Revise()
    {
        char name_[10];
        printf("请输入姓名:\n");
        scanf("%s", name_);
        int idx = Find(name_);
        if(idx > 0)
        {
            char na[10]; 
            int g; 
            int a; 
            char p[15]; 
            char add[30];
            printf("请输入姓名：\n");
            scanf("%s", na);
            printf("请输入性别:(女:0 男:1\n");
            scanf("%d", &g);
            printf("请输入年龄：\n");
            scanf("%d", &a);
            printf("请输入电话：\n");
            scanf("%s", p);
            printf("请输入地址：\n");
            scanf("%s", add);
            v[idx].SetInfo(na, g, a, p, add);
            printf("已修改完毕\n");
        }
        else
            printf("查无此人\n");
    }
    void Clear()
    {
        int check;
        printf("是否确定清空联系人?（是:1 否:0)\n");
        scanf("%d", &check);
        if(check)
            v.clear();
        printf("已清空\n");
    }
    bool DoSomething(int a) // 读取用户输入并执行
    {
        switch(a)
        {
            case 1: // 添加联系人
            {
                Add();
                break;
            }
            case 2: // 显示整个通讯录
            {
                Show();
                break;
            }
            case 3: // 删除联系人
            {
                Del();
                break;
            }
            case 4: // 查找联系人
            {
                Search();
                break;
            }
            case 5: // 编辑联系人
            {
                Revise();
                break;
            }
            case 6: // 清空通讯录
            {
                Clear();
                break;
            }
            case 0: // 退出通讯录
            {
                return true;
            }
            default:
                system("cls");
        }
        return false;
    }
}Myadd;

int main()
{
    Myadd.Init();
    while(true)
    {
        int tmp;
        Myadd.Menu();
        scanf("%d", &tmp);
        bool flag = Myadd.DoSomething(tmp);
        if(flag)
            break;
        system("pause");
        system("cls");
    }
    return 0;
}