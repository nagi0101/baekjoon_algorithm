#include <iostream>
#include <algorithm>
#include <vector>

#define CORRECT_DWARFS_NUM 7
#define ALL_DWARFS_NUM 9

using namespace std;

int main()
{
    vector<int> dwarfs;
    int sumOfAllDwarfsHeight = 0;
    
    for(int i=0; i<ALL_DWARFS_NUM; i++)
    {
        int input;
        cin >> input;
        dwarfs.push_back(input);
        sumOfAllDwarfsHeight += input;
    }

    bool terminateProgram=false;
terminate:
    if(!terminateProgram)
    {
        for(int i=0; i<ALL_DWARFS_NUM; i++)
        {
            for(int j=0; j<i; j++)
            {
                int sumOfExcludedDwarfsHeight = dwarfs[i] + dwarfs[j];
                int sumOfSelectedDwarfsHeight=sumOfAllDwarfsHeight-sumOfExcludedDwarfsHeight;
                if (sumOfSelectedDwarfsHeight == 100)
                {
                    dwarfs.erase(dwarfs.begin()+i);
                    dwarfs.erase(dwarfs.begin()+j);
                    sort(dwarfs.begin(), dwarfs.end());
                    for(int k=0; k<dwarfs.size(); k++)
                    {
                        cout << dwarfs[k] << endl;
                    }
                    terminateProgram=true;
                    goto terminate;
                }
            }
        }
    }
    return 0;
}