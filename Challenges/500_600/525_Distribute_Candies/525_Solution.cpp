int distributeCandies(vector<int>& candyType) {
    bitset<200001> hash;
    for(int i = 0; i < candyType.size(); i++)
        hash.set(candyType[i]+100000);
    return min((int)candyType.size()/2, (int)hash.count());     
}
