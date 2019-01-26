
Achievement Achi[5]={
  Achievement("[example]","[example]",150),
  Achievement("[example]","[example]",150),
  Achievement("[example]","[example]",150),
  Achievement("[example]","[example]",150),
  Achievement("[example]","[example]",150),
};


Game PC[5] = {
  Game("PUBG", "Steam", "Bluehole", Achi),
  Game("CS:GO", "Steam", "Valve", Achi),
  Game("GTA V", "Steam", "Rockstar", Achi),
  Game("Minecraft", "Mojang", "Mojang", Achi),
  Game("Farcry", "Steam", "Ubsoft", Achi)
};

Game XBOX[5] = {
  Game("Call of Duty", "Microsoft Store", "Activision Blizzard", Achi),
  Game("Rage", "Microsoft Store", "id Software", Achi),
  Game("Halo", "Microsoft Store", "Microsoft", Achi),
  Game("Sleeping Dogs", "Microsoft Store", "United Front Games", Achi),
  Game("Borderlands", "Microsoft Store", "2K Australia", Achi),
};

Game PS4[5] = {
  Game("God of War", "PlayStation Store", "Ready at Dawn", Achi),
  Game("Uncharted", "PlayStation Store", "Naughty Dog", Achi),
  Game("Days Gone", "PlayStation Store", "SIE Bend Studio", Achi),
  Game("Fortnite", "Epic Games", "Epic Games", Achi),
  Game("Just Caust", "Square Enix", "Avalanche Studios", Achi)
};

Game Switch[5] = {
  Game("Zelda", "Nintendo", "Nintendo", Achi),
  Game("Mario Kart", "Nintendo", "Nintendo", Achi),
  Game("Diablo", "Blizzard Entertainment", "Blizzard Entertainment", Achi),
  Game("Doom", "Bethesda Softworks", "id Software", Achi),
  Game("Wolfenstein", "Square Enix", "Avalanche Studios", Achi)
};

Game Wii[5] = {
  Game("Super Mario Galaxy", "Nintendo", "Nintendo", Achi),
  Game("Super Sonic", "Nintendo", "Nintendo", Achi),
  Game("FIFA", "Blizzard Entertainment", "Blizzard Entertainment", Achi),
  Game("Wii Sports", "Bethesda Softworks", "id Software", Achi),
  Game("Resident Evil", "Square Enix", "Avalanche Studios", Achi)
};

Platform p[5]={
  Platform("PC","Microsoft", PC),
  Platform("XBOX", "Microsoft", XBOX),
  Platform("PS4", "Sony", PS4),
  Platform("Switch","Nintendo", Switch),
  Platform("Wii","Nintendo", Wii)
};
