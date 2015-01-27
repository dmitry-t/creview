package com.data.hints.app;

import android.app.NotificationManager;
import android.content.Context;
import android.support.v4.app.NotificationCompat;

import java.util.Date;

public class NotificationService {

    private Context context_;
    private int counter_;

    public NotificationService(Context context) {
        context_ = context;
        counter_ = 0;
    }

    public void notify(CharSequence title, CharSequence text, Date issueTime) {
        ((NotificationManager) context_.getSystemService(Context.NOTIFICATION_SERVICE))
                .notify(++counter_,
                        new NotificationCompat.Builder(context_)
                                .setSmallIcon(android.R.drawable.ic_dialog_info)
                                .setContentTitle(title)
                                .setContentText(text)
                                .build());
    }
}
