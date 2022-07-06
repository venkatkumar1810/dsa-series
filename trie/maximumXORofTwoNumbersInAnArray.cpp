struct Node {
    Node * links[2];
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    
    Node * get(int bit){
        return links[bit];    
    }
    
    void put(int bit, Node * node){
        links[bit] = node;
    }
    
    
};
class Trie{
    private: Node * root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node * node = root;
        for(int i =  31; i>= 0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }       
    }
    int getMax(int num){
        Node * node = root;
        int maxNum = 0;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1 - bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1 - bit);
            } else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie trie;
    for(auto &it: A) trie.insert(it);
    int maxi = 0;
    for(auto &it : A) maxi = max(maxi, trie.getMax(it));
    
    return maxi;
}
