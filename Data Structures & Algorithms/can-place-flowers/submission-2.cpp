class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        int spots=0;
        /*if (flowerbed.size()>1 and flowerbed[0]+flowerbed[1]==0) {
            flowerbed[0]=1;
            spots++;
        }*/
        for (int i=1; i<flowerbed.size()-1; i++) {
            if (flowerbed[i-1]+flowerbed[i]+flowerbed[i+1]==0){
                spots++;
                flowerbed[i]=1;
            }
        }
        /*if (flowerbed.size()>1 and flowerbed[flowerbed.size()-2]+flowerbed[flowerbed.size()-1]==0) {
            flowerbed[flowerbed.size()-1]=1;
            spots++;
        }*/
        cout << spots;
        return spots>=n;
    }
};