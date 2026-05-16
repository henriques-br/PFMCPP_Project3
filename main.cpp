/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct CoffeeShop
{
    CoffeeShop();
    
    int numOfCoffeeMachines = 4;
    int numOfEmployees = 8;
    float amountOfCoffeBeanInStorage = 25.f;
    double dailyProfitAmount =  1500;
    std::string shopName = "Prenda Cafe";
    
    struct CoffeeMachine
    {
        std::string machineModelName = "Nespresso Aguila 440";
        float waterTankCapacityInLiters = 2.5f;
        int numOfEspressoShotsMadeToday = 120;
        double machineTemperatureInCelsius = 93.5;
        bool isSteamWandEnabled = true;

        void makeEspresso(int numOfShots);
        void steamMilk(float milkAmountInMl);
        bool cleanMachine();
    };
    
    void brewCoffee(CoffeeMachine activeCoffeeMachine, int numOfCups);
    void serveCustomers(int numOfCustomers);
    void cleanTables(int numOfTables);
    
    CoffeeMachine currentCoffeeMachine;
};

CoffeeShop::CoffeeShop()
{
    std::cout << "CoffeeShop being constructed!" << std::endl;
}

void CoffeeShop::CoffeeMachine::makeEspresso(int numOfShots)
{
    numOfEspressoShotsMadeToday += numOfShots;

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

void CoffeeShop::brewCoffee(CoffeeMachine activeCoffeeMachine, int numOfCups)
{
    activeCoffeeMachine.makeEspresso(numOfCups);

    std::cout << "Brewing " << numOfCups << " cups of coffee\n";
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
    VideoGameConsole();
    
    int storageCapacityInGb = 500;
    int numOfInstalledGames = 15;
    float controllerBatteryLevel = 82;
    std::string consoleModelName = "PS5";
    std::string screenResolutionSetting = "1759X1354";
    
    void launchGame(std::string gameName);
    void saveGameProgress(std::string saveFileName);
    bool connectToInternet(std::string wifiName);
};

VideoGameConsole::VideoGameConsole()
{
    std::cout << "CoffeeShop being constructed!" << std::endl;
}

void VideoGameConsole::launchGame(std::string gameName)
{
    std::cout << "Launching " << gameName << "\n";
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
    FitnessTracker();
    
    float batteryPercentage = 75.f;
    int numOfStepsRecorded = 127;
    int heartRateValue = 145;
    std::string deviceColor = "Blue";
    double dailyCalorieCount = 645;
    
    struct WorkoutSession
    {
        WorkoutSession();
        
        std::string workoutType = "Running";
        int workoutDurationInMinutes = 45;
        double caloriesBurned = 520.5;
        int averageHeartRate = 138;
        bool isGpsTrackingEnabled = true;

        void startWorkout();
        void pauseWorkout();
        bool endWorkout();
    };
    
    void trackWorkout(WorkoutSession curWorkoutSession);
    void displayNotification(std::string notificationMessage);
    double monitorSleep(int hoursSlept);
    
    WorkoutSession currentWorkoutSession;
};

FitnessTracker::WorkoutSession::WorkoutSession()
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

FitnessTracker::FitnessTracker()
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
}

double FitnessTracker::monitorSleep(int hoursSlept)
{
    double sleepQualityScore = hoursSlept * 10.0;

    std::cout << "User slept for " << hoursSlept << " hours\n";

    return sleepQualityScore;
}

struct MusicStudio
{
    MusicStudio();
    
    int numOfStudioMonitors = 8;
    int numOfMicrophones = 10;
    double roomSizeInSquareFeet = 50;
    std::string recordingSoftwareName = "Logic Pro";
    float hourlyRentalPrice = 135.f;

    void recordVocals(std::string singerName);
    void mixAudioTracks(int numOfTracks);
    std::string exportMusicFile(std::string fileName);
};

MusicStudio::MusicStudio()
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

    return fileName;
}

struct Computer
{
    Computer();
    
    double cpuSpeedInGhz = 4;
    int amountRamInGb = 128;
    int storageSizeInGb = 8000;
    std::string operatingSystemName = "MacOS Tahoe";
    int numOfUsbPorts = 8;
    
    void runAudioSoftware(std::string softwareName);
    void saveProjectFile(std::string projectName);
    int processAudioPlugins(int numOfPlugins);
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl;
}

void Computer::runAudioSoftware(std::string softwareName)
{
    std::cout << "Running audio software " << softwareName << "\n";
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
    AudioInterface();
    
    int numOfInputChannels = 26;
    int numOfOutputChannels = 20;
    double sampleRateInKhz = 48000;
    bool isPhantonPowerEnabled = true;
    float headphoneOutputVolume = 45.5f;
    
    void convertAnalogToDigitalAudio();
    void sendAudioToStudioMonitors(float outputVolume);
    bool connectMicrophone(std::string microphoneName);
};

AudioInterface::AudioInterface()
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
    StudioMonitors();
    
    double speakerSizeInInches = 10;
    int powerOutputsInWatts = 1200;
    float frequencyResponseRangeInHz = 250;
    float volumeLevel = 45.f;
    double cabinetWidthInCm = 30;
    
    void playAudioPlayback(std::string audioFileName);
    void reproduceLowFrequencies();
    void monitorRecordingSession(int sessionDurationInMinutes);
};

StudioMonitors::StudioMonitors()
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
    MidiKeyboard();
    
    int numOfKeys = 88;
    int octaveRange = 7;
    bool isVelocitySensitivityEnabled = true;
    int numOfControlKnobs = 12;
    std::string usbConnectionType = "USB-C";
    
    void sendMidiNotes(int midiNoteNumber);
    void controlVirtualInstrument(std::string instrumentName);
    void adjustPluginParameter(std::string parameterName, float parameterValue);
};

MidiKeyboard::MidiKeyboard()
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
    Microphone();
    
    std::string microphoneType = "Condenser";
    float frequencyResponseRangeInHz = 80;
    double sensitivityLevel = 5;
    double cableLenghtInMeters = 2;
    int maximumSoundPressureLevelInDb = 12;
    
    void captureVocalRecording(std::string vocalistName);
    void recordAcousticInstrument(std::string instrumentName);
    bool reduceBackgroundNoise();   
};

Microphone::Microphone()
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
    std::cout << "Microphone being constructed!" << std::endl;
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
    
    std::cout << "=========== 6th UDT ===========" << std::endl;
    StudioMonitors studioMonitors;
    studioMonitors.playAudioPlayback("MixSession.wav");
    studioMonitors.reproduceLowFrequencies();
    studioMonitors.monitorRecordingSession(90);

    std::cout << "=========== 7th UDT ===========" << std::endl;
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
