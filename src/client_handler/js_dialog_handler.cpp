// Copyright (c) 2016 CEF Python, see the Authors file.
// All rights reserved. Licensed under BSD 3-clause license.
// Project website: https://github.com/cztomczak/cefpython

#include "js_dialog_handler.h"

JSDialogHandler::JSDialogHandler()
{
}


bool JSDialogHandler::OnJSDialog(CefRefPtr<CefBrowser> browser,
                                 const CefString& origin_url,
                                 JSDialogType dialog_type,
                                 const CefString& message_text,
                                 const CefString& default_prompt_text,
                                 CefRefPtr<CefJSDialogCallback> callback,
                                 bool& suppress_message)
{
    REQUIRE_UI_THREAD();
    bool ret = JavascriptDialogHandler_OnJavascriptDialog(
                                            browser, origin_url,
                                            dialog_type, message_text,
                                            default_prompt_text,
                                            callback, suppress_message);
    return ret;
}


bool JSDialogHandler::OnBeforeUnloadDialog(
                                    CefRefPtr<CefBrowser> browser,
                                    const CefString& message_text,
                                    bool is_reload,
                                    CefRefPtr<CefJSDialogCallback> callback)
{
    REQUIRE_UI_THREAD();
    bool ret = JavascriptDialogHandler_OnBeforeUnloadJavascriptDialog(
                                                browser, message_text,
                                                is_reload, callback);
    return ret;
}


void JSDialogHandler::OnResetDialogState(CefRefPtr<CefBrowser> browser)
{
    REQUIRE_UI_THREAD();
    // User implementation
    JavascriptDialogHandler_OnResetJavascriptDialogState(browser);
}


void JSDialogHandler::OnDialogClosed(CefRefPtr<CefBrowser> browser)
{
    REQUIRE_UI_THREAD();
    JavascriptDialogHandler_OnJavascriptDialogClosed(browser);
}
