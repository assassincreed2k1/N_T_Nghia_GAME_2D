#ifndef IMP_TIMER_H_
#define IMP_TIMER_H_

class ImpTimer
{
public:
       ImpTimer();
       ~ImpTimer();

       void start();
       void stop();
       void paused();
       void unpaused();

       int get_ticks() const;

       bool is_started() const;
       bool is_paused() const;

private:
       int start_tick_;
       int paused_tick_;

       bool is_paused_;
       bool is_started_;
};

#endif
