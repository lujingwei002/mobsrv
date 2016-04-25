
Task = {
    [1] = 'int32 uid',
    [2] = 'int32 taskid',
}

User = {
    [1] = 'int32 uid',
    [2] = 'string uname',
    [3] = 'vector<Task*> task_array',
    [5] = 'Task* task',
}

export('Task', 'User')

