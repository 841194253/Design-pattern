//
// Created by apple on 7/31/21.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <functional>
#include <deque>
#include <time.h>

using namespace std;

class Player
{
public:
    string name;
    int mSocre[3];

};

//创建选手
void Create_Player(map<int,Player> &lsit,vector<int> &v1)
{
    string seedName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 24; ++i)
    {
        Player p;
        p.name = "选手";
        p.name += seedName[i];

        for (int j = 0; j < 3; ++j)
        {
            p.mSocre[j] = 0;
        }

        int uID = 100 + i;
        lsit.insert(make_pair(uID,p));

        v1.push_back(uID);
    }
}

//选手抽签
void Set_Random(vector<int> &v)
{
    random_shuffle(v.begin(),v.end());
}

//比赛
void Set_Socre(int index, vector<int> &v1, map<int, Player> &Plsit, vector<int> &v2)
{
    srand((unsigned int) time(NULL));
    multimap<int,int,greater<int>> mGroup; //<分数，编号> 默认排序
    int groupindex = 0;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        deque<int> dScore;
        for (int j = 0; j < 10; ++j)
        {
            int score = rand() % 40 + 60;
            dScore.push_back(score);
        }
        sort(dScore.begin(),dScore.end());
        dScore.pop_back();//最高分
        dScore.pop_front();//最低分

        int totaoScore = accumulate(dScore.begin(),dScore.end(),0);//总分
        int avgScore = totaoScore/dScore.size();

        Plsit[*it].mSocre[index-1] = avgScore;

        //将当前选手的编号放到mGroup
        mGroup.insert(make_pair(avgScore,*it));

        groupindex++;
        if (groupindex % 6 == 0)
        {
            int numIndex = 0;
            for (multimap<int,int>::iterator mit = mGroup.begin(); mit != mGroup.end(); mit++)
            {
                if (numIndex >= 3)
                {
                    break;
                }
                v2.push_back((*mit).second);
                numIndex++;
            }
            mGroup.clear();
        }
    }
}

//打印晋级名单
void Show_Good_Player(int index, vector<int> &v2, map<int, Player> &mPlsit)
{
    cout << "第" << index << "轮晋级名单" << endl;
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << "姓名:" << mPlsit[*it].name <<" "<< "分数:" << mPlsit[*it].mSocre[index-1] << endl;
    }

}

int main()
{
    //定义map容器用来保存选手的信息
    map<int,Player> mPlist;

    //第一轮比赛的参赛列表
    vector<int> v1;//24人晋级12人

    //第二轮比赛参赛列表
    vector<int> v2;//12人晋级6个人

    //第三轮比赛参赛列表
    vector<int> v3;//6个人晋级3个人

    //最终的前三名
    vector<int> v4;

    //创建选手
    Create_Player(mPlist,v1);


    //第一轮比赛
    Set_Random(v1);
    Set_Socre(1,v1,mPlist,v2);
    Show_Good_Player(1,v2,mPlist);

//    //第二轮比赛
    Set_Random(v2);
    Set_Socre(2,v2,mPlist,v3);
    Show_Good_Player(2,v3,mPlist);

    //第三轮比赛
    Set_Random(v3);
    Set_Socre(3,v3,mPlist,v4);
    Show_Good_Player(3,v4,mPlist);



}

