package com.data.hints.app;

import android.app.IntentService;
import android.content.Intent;
import android.os.Bundle;

import com.google.android.gms.gcm.GoogleCloudMessaging;

public class PushIntentService extends IntentService {

    public PushIntentService() {
        super(PushIntentService.class.getSimpleName());
    }

    @Override
    protected void onHandleIntent(Intent intent) {
        final Bundle extras = intent.getExtras();
        final GoogleCloudMessaging messaging = GoogleCloudMessaging.getInstance(this);
        final String messageType = messaging.getMessageType(intent);
    }
}
