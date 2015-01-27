package com.data.hints.core;

import com.data.hints.app.NotificationService;

import java.util.Date;
import java.util.GregorianCalendar;

public class Task {

    private String title_;
    private String description_;
    private TriggerTime triggerTime_;

    public Task(String title, String description) {
        title_ = title;
        description_ = description;
        triggerTime_ = TriggerTime.UNDEFINED;
    }

    public void setTitle(String title) {
        title_ = title;
    }

    public String getTitle() {
        return title_;
    }

    public void setDescription(String description) {
        description_ = description;
    }

    public String getDescription() {
        return description_;
    }

    public void setTriggerTime(TriggerTime triggerTime) {
        triggerTime_ = triggerTime != null ? triggerTime : TriggerTime.UNDEFINED;
    }

    public TriggerTime getTriggerTime() {
        return triggerTime_;
    }

    public void perform(Date issueTime, NotificationService notificationService) {
        notificationService.notify(title_, description_, issueTime);
    }
}
