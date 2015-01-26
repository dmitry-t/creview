package com.data.hints.net;

import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.ResponseHandler;

import java.io.IOException;

public class ResponseReader implements ResponseHandler<String> {
    @Override
    public String handleResponse(HttpResponse httpResponse) throws ClientProtocolException, IOException {
        return "Dummy";
    }
}
