#include <iostream>
#include <string>
 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Foot
{
    int footSize = 0;

    void stepForward();
    int stepSize();
};

void Foot::stepForward()
{
    std::cout << "Foot steps forward.\n";
}

int Foot::stepSize()
{
    return footSize;
}

struct Person
{
    int age = 0;
    int height = 0;
    int distanceTraveled = 0;
    float hairLength = 0.f;
    float GPA = 0.f;
    unsigned int SATScore = 0;

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

struct CoffeeShop
{
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

void CoffeeShop::brewCoffee(CoffeeMachine activeCoffeeMachine,
                            int numOfCups)
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
    int storageCapacityInGb = 500;
    int numOfInstalledGames = 15;
    float controllerBatteryLevel = 82;
    std::string consoleModelName = "PS5";
    std::string screenResolutionSetting = "1759X1354";
    
    void launchGame(std::string gameName);
    void saveGameProgress(std::string saveFileName);
    bool connectToInternet(std::string wifiName);
};

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
    float batteryPercentage = 75.f;
    int numOfStepsRecorded = 127;
    int heartRateValue = 145;
    std::string deviceColor = "Blue";
    double dailyCalorieCount = 645;
    
    struct WorkoutSession
    {
        std::string workoutType = "Running";
        int workoutDurationInMinutes = 45;
        double caloriesBurned = 520.5;
        int averageHeartRate = 138;
        bool isGpsTrackingEnabled = true;

        void startWorkout();
        void pauseWorkout();
        bool endWorkout();
    };
    
    void trackWorkout(WorkoutSession currentWorkoutSession);
    void displayNotification(std::string notificationMessage);
    double monitorSleep(int hoursSlept);
    
    WorkoutSession currentWorkoutSession;
};

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

void FitnessTracker::trackWorkout(WorkoutSession currentWorkoutSession)
{
    std::cout << "Tracking workout type: " << currentWorkoutSession.workoutType << "\n";

    std::cout << "Workout duration: " << currentWorkoutSession.workoutDurationInMinutes << " minutes\n";
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
    int numOfStudioMonitors = 8;
    int numOfMicrophones = 10;
    double roomSizeInSquareFeet = 50;
    std::string recordingSoftwareName = "Logic Pro";
    float hourlyRentalPrice = 135.f;

    void recordVocals(std::string singerName);
    void mixAudioTracks(int numOfTracks);
    std::string exportMusicFile(std::string fileName);
};

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
    double cpuSpeedInGhz = 4;
    int amountRamInGb = 128;
    int storageSizeInGb = 8000;
    std::string operatingSystemName = "MacOS Tahoe";
    int numOfUsbPorts = 8;
    
    void runAudioSoftware(std::string softwareName);
    void saveProjectFile(std::string projectName);
    int processAudioPlugins(int numOfPlugins);
};

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
    int numOfInputChannels = 26;
    int numOfCoutputChannels = 20;
    double sampleRateInKhz = 48000;
    bool isPhantonPowerEnabled = true;
    float headphoneOutputVolume = 45.5f;
    
    void convertAnalogToDigitalAudio();
    void sendAudioToStudioMonitors(float outputVolume);
    bool connectMicrophone(std::string microphoneName);
};

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
    double speakerSizeInInches = 10;
    int powerOutputsInWatts = 1200;
    float frequencyResponseRangeInHz = 250;
    float volumeLevel = 45.f;
    double cabinetWidthInCm = 30;
    
    void playAudioPlayback(std::string audioFileName);
    void reproduceLowFrequencies();
    void monitorRecordingSession(int sessionDurationInMinutes);
};

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
    bool isVelocitySensitivityEnabled = true;
    int numOfControlKnobs = 12;
    std::string usbConnectionType = "USB-C";
    
    void sendMidiNotes(int midiNoteNumber);
    void controlVirtualInstrument(std::string instrumentName);
    void adjustPluginParameter(std::string parameterName, float parameterValue);
};

struct Microphone
{
    std::string microphoneType = "Condenser";
    float frequencyResponseRangeInHz = 80;
    double sensitivityLevel = 5;
    double cableLenghtInMeters = 2;
    int maximumSoundPressureLevelInDb = 12;
    
    void captureVocalRecording(std::string vocalistName);
    void recordAcousticInstrument(std::string instrumentName);
    bool reduceBackgroundNoise();   
};

struct MusicStudioComputerSetup
{
    Computer computer;
    AudioInterface audioInterface;
    StudioMonitors studioMonitors;
    MidiKeyboard midiKeyboard;
    Microphone microphone;
    
    void recordMusic(std::string projectName);
    void editAudioTrack(std::string trackName);
    void playVirtualInstrument(std::string instrumentName);
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
