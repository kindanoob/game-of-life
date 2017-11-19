#ifndef NODE_H_
#define NODE_H_



class Node {
public:
    Node(): i_(0), j_(0) {}
    Node(int i, int j): i_(i), j_(j) {}
    int i_;//row index
    int j_;//col index
    char data_ = '0';//default value for a node
    bool visited_ = false;
};


#endif //NODE_H_
