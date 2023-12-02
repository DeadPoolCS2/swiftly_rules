#include <swiftly/swiftly.h>
#include <swiftly/server.h>
#include <swiftly/database.h>
#include <swiftly/commands.h>
#include <swiftly/configuration.h>
#include <swiftly/logger.h>
#include <swiftly/timers.h>

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;
Database *db = nullptr;
Commands *commands = nullptr;
Configuration *config = nullptr;
Logger *logger = nullptr;
Timers *timers = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);

    server = new Server();
    g_playerManager = new PlayerManager();
    commands = new Commands(pluginName);
    config = new Configuration();
    logger = new Logger(mainFilePath, pluginName);
    timers = new Timers();
}

void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
        Player *player = g_playerManager->GetPlayer(playerID);
        if (!player)
            return;

        player->SendMsg(HUD_PRINTTALK, "[1TAP] -----------------------------------------------------");
        player->SendMsg(HUD_PRINTTALK, "Rule 1: "config->Fetch<const char*>("rules.rule1"),);
        player->SendMsg(HUD_PRINTTALK, "Rule 2: "config->Fetch<const char*>("rules.rule1"),);
        player->SendMsg(HUD_PRINTTALK, "Rule 3: "config->Fetch<const char*>("rules.rule1"),);
        player->SendMsg(HUD_PRINTTALK, "Rule 4: "config->Fetch<const char*>("rules.rule1"),);
        player->SendMsg(HUD_PRINTTALK, "Rule 5: "config->Fetch<const char*>("rules.rule1"),);
        player->SendMsg(HUD_PRINTTALK, "Rule 6: "config->Fetch<const char*>("rules.rule1"),);
        player->SendMsg(HUD_PRINTTALK, "Rule 7: "config->Fetch<const char*>("rules.rule1"),);
        player->SendMsg(HUD_PRINTTALK, "Rule 8: "config->Fetch<const char*>("rules.rule1"),);
        return;
}

void OnPluginStart()
{
    commands->Register("!rules", reinterpret_cast<void *>(&Command_Test));
    commands->Register("!reguli", reinterpret_cast<void *>(&Command_Test));
}

void OnPluginStop()
{
    timers->UnregisterTimers();
}

const char *GetPluginAuthor()
{
    return "";
}

const char *GetPluginVersion()
{
    return "1.0.0";
}

const char *GetPluginName()
{
    return "rules";
}

const char *GetPluginWebsite()
{
    return "";
}