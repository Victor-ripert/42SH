/*
** EPITECH PROJECT, 2025
** jobs.h
** File description:
** a .h for jobs
*/

#ifndef JOBS_H
    #define JOBS_H
    #include <sys/wait.h>

typedef enum {
    JOB_RUNNING = 0,
    JOB_STOPPED = 1,
    JOB_DONE = 2,
    JOB_TERMINATED = 3
} JobStatus_t;

typedef struct jobs_s {
    int job_id;
    pid_t pgid;
    JobStatus_t status;
    char *command;
    struct jobs_s *next;
} jobs_t;

#endif
