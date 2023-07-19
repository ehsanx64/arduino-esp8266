#ifndef WEBSERVER_DEFINED
#define WEBSERVER_DEFINED

/*
 * Configuration
 */
#define WEBSERVER_ENABLED true

// Function prototypes (global)
void WebServer_Setup();
void WebServer_Loop();
void WebServer_NotFoundHandler();
#endif
