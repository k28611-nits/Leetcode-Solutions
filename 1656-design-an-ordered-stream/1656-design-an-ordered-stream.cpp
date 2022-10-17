class OrderedStream {
public:
    vector<string> stream;
    int i=0;
    OrderedStream(int n) {
        stream.resize(n);
    }
    
    vector<string> insert(int id, string value) {
        vector<string> result;
        stream[id-1]=value;
        while(i<stream.size() and stream[i]!="")
        {
            result.push_back(stream[i]);
            i++;
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */