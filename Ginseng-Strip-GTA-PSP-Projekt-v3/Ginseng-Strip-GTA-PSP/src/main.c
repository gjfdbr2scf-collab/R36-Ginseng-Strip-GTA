#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>

PSP_MODULE_INFO("Ginseng Strip GTA", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

static int exit_callback(int arg1, int arg2, void *common)
{
    (void)arg1; (void)arg2; (void)common;
    sceKernelExitGame();
    return 0;
}

static int CallbackThread(SceSize args, void *argp)
{
    (void)args; (void)argp;
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);
    sceKernelSleepThreadCB();
    return 0;
}

static int setup_callbacks(void)
{
    int thid = sceKernelCreateThread("update_thread", CallbackThread,
                                     0x11, 0xFA0, 0, NULL);
    if (thid >= 0) sceKernelStartThread(thid, 0, NULL);
    return thid;
}

int main(void)
{
    setup_callbacks();
    pspDebugScreenInit();

    pspDebugScreenPrintf("GINSENG STRIP GTA\n");
    pspDebugScreenPrintf("-----------------\n\n");
    pspDebugScreenPrintf("PSP GAME BOOT OK\n");
    pspDebugScreenPrintf("Project: Ginseng Strip GTA\n");
    pspDebugScreenPrintf("First-person PSP build\n\n");
    pspDebugScreenPrintf("BLACK-SCREEN CHECK: BOOT DISPLAY ACTIVE\n");
    pspDebugScreenPrintf("\nPress START to continue.\n");

    SceCtrlData pad;
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_DIGITAL);

    for (;;) {
        sceCtrlReadBufferPositive(&pad, 1);
        if (pad.Buttons & PSP_CTRL_START) {
            pspDebugScreenClear();
            pspDebugScreenPrintf("GINSENG STRIP GTA\n\n");
            pspDebugScreenPrintf("MAIN MENU\n\n");
            pspDebugScreenPrintf("> START (STORY MODE)\n");
            pspDebugScreenPrintf("  FREE OPEN WORLD\n");
            pspDebugScreenPrintf("  MULTIPLAYER (LOCAL)\n");
            pspDebugScreenPrintf("  OPTIONS\n");
            pspDebugScreenPrintf("  CREDITS\n");
            pspDebugScreenPrintf("  QUIT\n");
            pspDebugScreenPrintf("\nGAME PROJECT BOOTED SUCCESSFULLY.\n");
            pspDebugScreenPrintf("Full game systems are being built into this core.\n");
            sceKernelSleepThread();
        }
        sceDisplayWaitVblankStart();
    }

    return 0;
}
