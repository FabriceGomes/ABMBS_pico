#ifndef MYTASK_H__
#define MYTASK_H__

static void killmeTask(void *pv);

static void otherTask (void *pv );

static void mainTask(void *pv);

void MyTasks_Deinit(void);

void MyTask_Init (void);


#endif