class Number
{
    char* Value;
    int Decimal;
    int Base;
public:
    Number(const char* value, int base);
    Number(const int value);
    Number(const Number& n);
    Number(Number&& n);
    Number();
    ~Number();

    void operator=(const Number&);
    void operator=(int);
    void operator=(const char*);
    Number operator+(const Number&);
    void operator+=(const Number&);
    Number operator-(const Number&);
    void operator-=(const Number&);

    bool operator==(const Number&);
    bool operator<=(const Number&);
    bool operator>=(const Number&);
    bool operator>(const Number&);
    bool operator<(const Number&);

    void operator--(int);
    void operator--();

    char operator[](const int);

    void SwitchBase(int newBase);
    void Print() const;
    int  GetDigitsCount() const; 
    int  GetBase() const; 
};