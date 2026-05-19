/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



struct CoffeeShop
{
    int numOfCoffeeMachines;
    int numOfEmployees;
    float amountOfCoffeBeanInStorage = 25.f;
    double dailyProfitAmount =  1500;
    std::string shopName = "Prenda Cafe";

    CoffeeShop();

    struct CoffeeMachine
    {
        std::string machineModelName;
        float waterTankCapacityInLiters;
        int numOfEspressoShotsMadeToday = 120;
        double machineTemperatureInCelsius;
        bool isSteamWandEnabled = true;

        CoffeeMachine();

        void makeEspresso(int numOfShots);
        void steamMilk(float milkAmountInMl);
        bool cleanMachine();
    };
    
    void brewCoffee(CoffeeMachine activeCoffeeMachine, int numOfCups);
    void serveCustomers(int numOfCustomers);
    void cleanTables(int numOfTables);
    
    CoffeeMachine currentCoffeeMachine;
};

CoffeeShop::CoffeeMachine::CoffeeMachine() :
    machineModelName("Perfect Brew"),
    waterTankCapacityInLiters(3.2f),
    numOfEspressoShotsMadeToday(0),
    machineTemperatureInCelsius(92.0),
    isSteamWandEnabled(true)
{
    std::cout << "CoffeeMachine constructed!\n";
}

void CoffeeShop::CoffeeMachine::makeEspresso(int numOfShots)
{
    numOfEspressoShotsMadeToday += numOfShots;
    std::cout << "Machine Model: " << machineModelName << '\n';
    std::cout << "Water Tank Capacity: " << waterTankCapacityInLiters << " liters\n\n";

    std::cout << "Making " << numOfShots << " " << (numOfShots == 1 ? "cup" : "cups") << " espresso shots\n";
}

void CoffeeShop::CoffeeMachine::steamMilk(float milkAmountInMl)
{
    std::cout << "Steaming " << milkAmountInMl << " ml of milk\n";
}

bool CoffeeShop::CoffeeMachine::cleanMachine()
{
    std::cout << "Cleaning coffee machine\n";

    return true;
}

CoffeeShop::CoffeeShop(): numOfCoffeeMachines(6), numOfEmployees(9)
{
    std::cout << "CoffeeShop being constructed!" << std::endl;
}

void CoffeeShop::brewCoffee(CoffeeMachine activeCoffeeMachine, int numOfCups)
{
    activeCoffeeMachine.makeEspresso(numOfCups);

    std::cout << "Brewing " << numOfCups << " cups of coffee\n";
    std::cout << "Shop Name: " << shopName << '\n';
    std::cout << "Employees: " << numOfEmployees << '\n';
    std::cout << "Coffee Machines: " << numOfCoffeeMachines << "\n\n";
}

void CoffeeShop::serveCustomers(int numOfCustomers)
{
    std::cout << "Serving " << numOfCustomers << " customers\n";
}

void CoffeeShop::cleanTables(int numOfTables)
{
    std::cout << "Cleaning " << numOfTables << " tables\n";
}

struct VideoGameConsole
{
    int storageCapacityInGb;
    int numOfInstalledGames;
    float controllerBatteryLevel = 82;
    std::string consoleModelName;
    std::string screenResolutionSetting = "1759X1354";

    VideoGameConsole();

    void launchGame(std::string gameName);
    void saveGameProgress(std::string saveFileName);
    bool connectToInternet(std::string wifiName);
};

VideoGameConsole::VideoGameConsole():
    storageCapacityInGb(1000),
    numOfInstalledGames(6),
    consoleModelName("Xbox One")
{
    std::cout << "VideoGameConsole being constructed!" << std::endl;
}

void VideoGameConsole::launchGame(std::string gameName)
{
    std::cout << "Launching " << gameName << "\n";
    std::cout << "Storage Capacity in GB: " << storageCapacityInGb << '\n';
    std::cout << "Installed Games: " << numOfInstalledGames << '\n';
    std::cout << "Console Model Name: " << consoleModelName << "\n\n";
}

void VideoGameConsole::saveGameProgress(std::string saveFileName)
{
    std::cout << "Saving game file " << saveFileName << "\n";
}

bool VideoGameConsole::connectToInternet(std::string wifiName)
{
    std::cout << "Connecting to wifi network " << wifiName << "\n";

    return true;
}


struct FitnessTracker
{
    float batteryPercentage;
    int numOfStepsRecorded;
    int heartRateValue = 145;
    std::string deviceColor;
    double dailyCalorieCount = 645;

    FitnessTracker();
       
    struct WorkoutSession
    {
        std::string workoutType;
        int workoutDurationInMinutes;
        double caloriesBurned = 520.5;
        int averageHeartRate = 138;
        bool isGpsTrackingEnabled;

        WorkoutSession();

        void startWorkout();
        void pauseWorkout();
        bool endWorkout();
    };
    
    void trackWorkout(WorkoutSession curWorkoutSession);
    void displayNotification(std::string notificationMessage);
    double monitorSleep(int hoursSlept);
    
    WorkoutSession currentWorkoutSession;
};

FitnessTracker::WorkoutSession::WorkoutSession():
    workoutType("Walking"),
    workoutDurationInMinutes(55),
    isGpsTrackingEnabled(false)
{
 std::cout << "WorkoutSession being constructed!" << std::endl;
}

void FitnessTracker::WorkoutSession::startWorkout()
{
    std::cout << "Starting " << workoutType << " workout\n";
}

void FitnessTracker::WorkoutSession::pauseWorkout()
{
    std::cout << "Pausing " << workoutType << " workout\n";
}

bool FitnessTracker::WorkoutSession::endWorkout()
{
    std::cout << "Ending " << workoutType << " workout\n";

    return true;
}

FitnessTracker::FitnessTracker():
    batteryPercentage(75.f),
    numOfStepsRecorded(127),
    deviceColor("Black")
{
    std::cout << "FitnessTracker being constructed!" << std::endl;
}


void FitnessTracker::trackWorkout(WorkoutSession curWorkoutSession)
{
    std::cout << "Tracking workout type: " << curWorkoutSession.workoutType << "\n";

    std::cout << "Workout duration: " << curWorkoutSession.workoutDurationInMinutes << " minutes\n";
}

void FitnessTracker::displayNotification(std::string notificationMessage)
{
    std::cout << "Notification: " << notificationMessage << "\n";
    std::cout << "Number of steps recorded: " << numOfStepsRecorded << "\n";
    std::cout << "Battery Level: " << batteryPercentage << "\n";
}


double FitnessTracker::monitorSleep(int hoursSlept)
{
    double sleepQualityScore = hoursSlept * 10.0;

    std::cout << "User slept for " << hoursSlept << " hours\n";

    return sleepQualityScore;
}

struct MusicStudio
{
    int numOfStudioMonitors = 8;
    int numOfMicrophones = 10;
    double roomSizeInSquareFeet = 50;
    std::string recordingSoftwareName;
    float hourlyRentalPrice;

    MusicStudio();
    
    void recordVocals(std::string singerName);
    void mixAudioTracks(int numOfTracks);
    std::string exportMusicFile(std::string fileName);
};

MusicStudio::MusicStudio():
    recordingSoftwareName("Reaper"),
    hourlyRentalPrice(155.f)
{
    std::cout << "MusicStudio being constructed!" << std::endl;
}

void MusicStudio::recordVocals(std::string singerName)
{
    std::cout << "Recording vocals for " << singerName << "\n";
}

void MusicStudio::mixAudioTracks(int numOfTracks)
{
    std::cout << "Mixing " << numOfTracks << " audio tracks\n";
}

std::string MusicStudio::exportMusicFile(std::string fileName)
{
    std::cout << "Exporting music file " << fileName << "\n";
    std::cout << "Recording Software Used " << recordingSoftwareName << "\n";

    return fileName;
}

struct Computer
{
    double cpuSpeedInGhz;
    int amountRamInGb;
    int storageSizeInGb = 8000;
    std::string operatingSystemName;
    int numOfUsbPorts = 8;

    Computer();
       
    void runAudioSoftware(std::string softwareName);
    void saveProjectFile(std::string projectName);
    int processAudioPlugins(int numOfPlugins);
};

Computer::Computer():
    cpuSpeedInGhz(4),
    amountRamInGb(128),
    operatingSystemName("MacOS Tahoe")

{
    std::cout << "Computer being constructed!" << std::endl;
}

void Computer::runAudioSoftware(std::string softwareName)
{
    std::cout << "Running audio software " << softwareName << "\n";
    std::cout << "Operating System Name " << operatingSystemName << "\n";
}

void Computer::saveProjectFile(std::string projectName)
{
    std::cout << "Saving project file " << projectName << "\n";
}

int Computer::processAudioPlugins(int numOfPlugins)
{
    std::cout << "Processing " << numOfPlugins << " audio plugins\n";

    return numOfPlugins;
}

struct AudioInterface
{
    int numOfInputChannels;
    int numOfOutputChannels;
    double sampleRateInKhz;
    bool isPhantomPowerEnabled = true;
    float headphoneOutputVolume = 45.5f;

    AudioInterface();
       
    void convertAnalogToDigitalAudio();
    void sendAudioToStudioMonitors(float outputVolume);
    bool connectMicrophone(std::string microphoneName);
};

AudioInterface::AudioInterface():
    numOfInputChannels(26),
    numOfOutputChannels(20),
    sampleRateInKhz(48000)
{
    std::cout << "AudioInterface being constructed!" << std::endl;
}


void AudioInterface::convertAnalogToDigitalAudio()
{
    std::cout << "Converting analog audio to digital audio\n";
}

void AudioInterface::sendAudioToStudioMonitors(float outputVolume)
{
    headphoneOutputVolume = outputVolume;

    std::cout << "Sending audio to studio monitors at volume " << outputVolume << "\n";
}

bool AudioInterface::connectMicrophone(std::string microphoneName)
{
    std::cout << "Connecting microphone " << microphoneName << "\n";

    return true;
}

struct StudioMonitors
{
    double speakerSizeInInches;
    int powerOutputsInWatts;
    float frequencyResponseRangeInHz;
    float volumeLevel = 45.f;
    double cabinetWidthInCm = 30;

    StudioMonitors();
      
    void playAudioPlayback(std::string audioFileName);
    void reproduceLowFrequencies();
    void monitorRecordingSession(int sessionDurationInMinutes);
};

StudioMonitors::StudioMonitors():
    speakerSizeInInches(10),
    powerOutputsInWatts(1200),
    frequencyResponseRangeInHz(250)
{
    std::cout << "StudioMonitors being constructed!" << std::endl;
}

void StudioMonitors::playAudioPlayback(std::string audioFileName)
{
    std::cout << "Playing audio file " << audioFileName << "\n";
}

void StudioMonitors::reproduceLowFrequencies()
{
    std::cout << "Reproducing low frequencies\n";
}

void StudioMonitors::monitorRecordingSession(int sessionDurationInMinutes)
{
    std::cout << "Monitoring recording session for " << sessionDurationInMinutes << " minutes\n";
}

struct MidiKeyboard
{
    int numOfKeys = 88;
    int octaveRange = 7;
    bool isVelocitySensitivityEnabled;
    int numOfControlKnobs = 12;
    std::string usbConnectionType;

    MidiKeyboard();
       
    void sendMidiNotes(int midiNoteNumber);
    void controlVirtualInstrument(std::string instrumentName);
    void adjustPluginParameter(std::string parameterName, float parameterValue);
};

MidiKeyboard::MidiKeyboard():
    isVelocitySensitivityEnabled(true),
    usbConnectionType("USB-C")
{
    std::cout << "MidiKeyboard being constructed!" << std::endl;
}

void MidiKeyboard::sendMidiNotes(int midiNoteNumber)
{
    std::cout << "Sending MIDI note " << midiNoteNumber << "\n";
}

void MidiKeyboard::controlVirtualInstrument(std::string instrumentName)
{
    std::cout << "Controlling virtual instrument " << instrumentName << "\n";
}

void MidiKeyboard::adjustPluginParameter(std::string parameterName, float parameterValue)
{
    std::cout << "Adjusting parameter " << parameterName << " to " << parameterValue << "\n";
}

struct Microphone
{
    std::string microphoneType;
    float frequencyResponseRangeInHz = 80;
    double sensitivityLevel;
    double cableLenghtInMeters;
    int maximumSoundPressureLevelInDb = 12;

    Microphone();
       
    void captureVocalRecording(std::string vocalistName);
    void recordAcousticInstrument(std::string instrumentName);
    bool reduceBackgroundNoise();
};

Microphone::Microphone():
    microphoneType("Condenser"),
    sensitivityLevel(7),
    cableLenghtInMeters(5)
{
    std::cout << "Microphone being constructed!" << std::endl;
}

void Microphone::captureVocalRecording(std::string vocalistName)
{
    std::cout << "Capturing vocals for " << vocalistName << "\n";
}

void Microphone::recordAcousticInstrument(std::string instrumentName)
{
    std::cout << "Recording acoustic instrument " << instrumentName << "\n";
}

bool Microphone::reduceBackgroundNoise()
{
    std::cout << "Reducing background noise\n";

    return true;
}

struct MusicStudioComputerSetup
{
    MusicStudioComputerSetup();
    
    Computer computer;
    AudioInterface audioInterface;
    StudioMonitors studioMonitors;
    MidiKeyboard midiKeyboard;
    Microphone microphone;
    
    void recordMusic(std::string projectName);
    void editAudioTrack(std::string trackName);
    void playVirtualInstrument(std::string instrumentName);
};

MusicStudioComputerSetup::MusicStudioComputerSetup()
{
    std::cout << "MusicStudioComputerSetup being constructed!" << std::endl;
}

void MusicStudioComputerSetup::recordMusic(std::string projectName)
{
    computer.runAudioSoftware(projectName);

    microphone.captureVocalRecording("Lead Vocalist");

    audioInterface.convertAnalogToDigitalAudio();

    std::cout << "Recording music project: " << projectName << "\n";
}

void MusicStudioComputerSetup::editAudioTrack(std::string trackName)
{
    computer.saveProjectFile(trackName);

    studioMonitors.monitorRecordingSession(60);

    std::cout << "Editing audio track: " << trackName << "\n";
}

void MusicStudioComputerSetup::playVirtualInstrument(std::string instrumentName)
{
    midiKeyboard.controlVirtualInstrument(instrumentName);

    studioMonitors.playAudioPlayback(instrumentName);

    std::cout << "Playing virtual instrument: " << instrumentName << "\n";
}

int main()
{
    Example::main();

    //add your code here:
    std::cout << "=========== 1st UDT ===========" << std::endl;
    CoffeeShop coffeeShop;
    coffeeShop.serveCustomers(12);
    coffeeShop.cleanTables(5);
    coffeeShop.currentCoffeeMachine.makeEspresso(3);
    coffeeShop.currentCoffeeMachine.steamMilk(250.0f);
    coffeeShop.currentCoffeeMachine.cleanMachine();
    coffeeShop.brewCoffee(coffeeShop.currentCoffeeMachine, 10);

    std::cout << "=========== 2nd UDT ===========" << std::endl;
    VideoGameConsole ps5;
    ps5.launchGame("FIFA 2026");
    ps5.saveGameProgress("save_file_01");
    std::cout << "Is console connected to internet? " << (ps5.connectToInternet("StudioWifi") == 1 ? "Yes" : "No") << "\n";

    std::cout << "=========== 3rd UDT with nested ===========" << std::endl;
    FitnessTracker fitnessTracker;
    fitnessTracker.currentWorkoutSession.startWorkout();
    fitnessTracker.trackWorkout(fitnessTracker.currentWorkoutSession);
    fitnessTracker.displayNotification("Goal reached");
    fitnessTracker.monitorSleep(8);
    fitnessTracker.currentWorkoutSession.pauseWorkout();
    fitnessTracker.currentWorkoutSession.endWorkout();

    std::cout << "=========== 4th UDT ===========" << std::endl;
    MusicStudio musicStudio;
    musicStudio.recordVocals("Alex");
    musicStudio.mixAudioTracks(12);
    musicStudio.exportMusicFile("PFMSong.wav");

    std::cout << "=========== 5th UDT ===========" << std::endl;
    Computer studioComputer;
    studioComputer.runAudioSoftware("Reaper");
    studioComputer.saveProjectFile("AlbumSession");
    studioComputer.processAudioPlugins(15);
    
    std::cout << "=========== 6th UDT ===========" << std::endl;
    AudioInterface audioInterface;
    audioInterface.convertAnalogToDigitalAudio();
    audioInterface.sendAudioToStudioMonitors(75.0f);
    audioInterface.connectMicrophone("Shure SM7B");
    
    std::cout << "=========== 7th UDT ===========" << std::endl;
    StudioMonitors studioMonitors;
    studioMonitors.playAudioPlayback("MixSession.wav");
    studioMonitors.reproduceLowFrequencies();
    studioMonitors.monitorRecordingSession(90);

    std::cout << "=========== 8th UDT ===========" << std::endl;
    MidiKeyboard midiKeyboard;
    midiKeyboard.sendMidiNotes(64);
    midiKeyboard.controlVirtualInstrument("Pianoteq 9");
    midiKeyboard.adjustPluginParameter("Reverb Mix", 0.75f);
    
    std::cout << "=========== 9th UDT ===========" << std::endl;
    Microphone microphone;
    microphone.captureVocalRecording("Lead Singer");
    microphone.recordAcousticInstrument("Acoustic Guitar");
    microphone.reduceBackgroundNoise();

    std::cout << "=========== 10th UDT with nested ===========" << std::endl;
    MusicStudioComputerSetup setup;
    setup.recordMusic("New Album");
    setup.editAudioTrack("Lead Vocals");
    setup.playVirtualInstrument("Synth Pad");

    std::cout << "good to go!" << std::endl;
}
