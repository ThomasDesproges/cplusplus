class IntStack {
public:
  IntStack (int s);
  IntStack(const IntStack& rst);
  ~IntStack();
  void push (int e);
  int pop ();
  void print ();
  bool is_full();
  bool is_empty();
private:
  int size;
  int top;
  int* tab;
};