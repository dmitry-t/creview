package com.data.hints.schedule;

import com.data.hints.app.NotificationService;
import com.data.hints.core.Task;

import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

public class Scheduler {

    private final Timer timer_;
    private NotificationService notificationService_;

    public Scheduler(NotificationService notificationService) {
        notificationService_ = notificationService;
        timer_ = new Timer();
    }

    public void schedule(final Task task, final Date issueTime) {
        timer_.schedule(
                new TimerTask() {
                    @Override
                    public void run() {
                        task.perform(issueTime, notificationService_);
                    }
                },
                issueTime);
    }
}
