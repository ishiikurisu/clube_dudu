class thread
{
  public:
  int period;
  int last_call;
  void (*command)();

  thread (void (*function)(), int new_period)
  {
    command = function;
    period = new_period;
    last_call = 0;
  }

  void execute()
  {
    command();
  }
};
