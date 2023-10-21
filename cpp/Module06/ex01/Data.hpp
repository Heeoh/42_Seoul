#ifndef DATA_HPP
# define DATA_HPP

class Data {
    int value;

    Data();

public:
    Data(int val);
    Data(const Data & obj);
    Data& operator=(const Data & obj);
    ~Data();

    int getData() const;
    void setData(int val);
};

#endif