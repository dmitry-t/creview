package com.data.hints.net;

import android.net.http.AndroidHttpClient;
import android.os.AsyncTask;

import org.apache.http.client.ResponseHandler;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpUriRequest;

import java.io.IOException;
import java.net.URI;

public class Client {
    private AndroidHttpClient httpClient_;
    private ResponseHandler<String> responseHandler_;

    public Client(ResponseHandler<String> responseHandler) {
        responseHandler_ = responseHandler;
        httpClient_ = AndroidHttpClient.newInstance(Const.USER_AGENT);
    }

    public void get(final String uri, final Listener listener) {
        new AsyncTask<Void, Void, Void>() {
            @Override
            protected Void doInBackground(Void... dummy) {
                try {
                    listener.onResponse(httpClient_.execute(new HttpGet(uri), responseHandler_));
                } catch (IOException e) {
                    e.printStackTrace();
                    listener.onError();
                }
                return null;
            }
        }.execute();
    }
}
