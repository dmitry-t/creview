package com.data.hints.core;

import java.util.Date;

public class Notification {
    public final int id;
    public final CharSequence title;
    public final CharSequence text;
    public final Date issueTime;

    public Notification(int id, CharSequence title, CharSequence text, Date issueTime) {
        this.id = id;
        this.title = title;
        this.text = text;
        this.issueTime = issueTime;
    }
}
