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
    // number of coffee machines (int)
    int numOfCoffeeMachines = 4;
    // number of employees (int)
    int numOfEmployees = 8;
    // amount of coffee beans in storage (float)
    float amountOfCoffeBeanInStorage = 25.f;
    // daily profit amount (double)
    double dailyProfitAmount =  1500;
    // shop name (std::string)
    std::string shopName = "Prenda Cafe";
    
    //this is the nested UDT:
    struct CoffeeMachine
    {
        // machine model name (std::string)
        std::string machineModelName = "Nespresso Aguila 440";
        // water tank capacity in liters (float)
        float waterTankCapacityInLiters = 2.5f;
        // number of espresso shots made today (int)
        int numOfEspressoShotsMadeToday = 120;
        // machine temperature in Celsius (double)
        double machineTemperatureInCelsius = 93.5;
        // steam wand enabled (bool)
        bool isSteamWandEnabled = true;

        //3 things it can do:
        //1) make espresso
        void makeEspresso(int numOfShots);

        //2) steam milk
        void steamMilk(float milkAmountInMl);

        //3) clean machine
        bool cleanMachine(); // returns true if cleaning was successful
    };
    
    //3 things it can do:
    //1) brew coffee
    void brewCoffee(CoffeeMachine activeCoffeeMachine, int numOfCups);
    
    //2) serve customers
    void serveCustomers(int numOfCustomers);
    
    //3) clean tables
    void cleanTables(int numOfTables);
    
    // member variable whose type is a UDT
    CoffeeMachine currentCoffeeMachine;
};
struct VideoGameConsole
{
    // storage capacity in gigabytes (int)
    int storageCapacityInGb = 500;
    // number of installed games (int)
    int numOfInstalledGames = 15;
    // controller battery level (float)
    float controllerBatteryLevel = 82;
    // console model name (std::string)
    std::string consoleModelName = "PS5";
    // screen resolution setting (std::string)
    std::string screenResolutionSetting = "1759X1354";
    
    //3 things it can do:
    //    1) launch games
    void launchGame(std::string gameName);
    
    //    2) save game progress
    void saveGameProgress(std::string saveFileName);
    
    //    3) connect to the internet
    bool connectToInternet(std::string wifiName);   // returns true if connection was successful
};
struct FitnessTracker
{
    // battery percentage (float)
    float batteryPercentage = 75.f;
    // number of steps recorded (int)
    int numOfStepsRecorded = 127;
    // heart rate value (int)
    int heartRateValue = 145;
    // device color (std::string)
    std::string deviceColor = "Blue";
    // daily calorie count (double)
    double dailyCalorieCount = 645;
    
    //this is the nested UDT:
    struct WorkoutSession
    {
        // workout type (std::string)
        std::string workoutType = "Running";

        // workout duration in minutes (int)
        int workoutDurationInMinutes = 45;

        // calories burned (double)
        double caloriesBurned = 520.5;

        // average heart rate (int)
        int averageHeartRate = 138;

        // GPS tracking enabled (bool)
        bool isGpsTrackingEnabled = true;

        //3 things it can do:
        //1) start workout
        void startWorkout();

        //2) pause workout
        void pauseWorkout();

        //3) end workout
        bool endWorkout(); // returns true if workout ended successfully
        
    };
    
    //3 things it can do:
    //    1) track workouts
    void trackWorkout(WorkoutSession currentWorkoutSession);
    
    //    2) display notifications
    void displayNotification(std::string notificationMessage);
    
    //    3) monitor sleep
    double monitorSleep(int hoursSlept);    // returns total hours slept
    
    // member variable whose type is a UDT
    WorkoutSession currentWorkoutSession;
};
struct MusicStudio
{
    // number of studio monitors (int)
    int numOfStudioMonitors = 8;
    // number of microphones )int)
    int numOfMicrophones = 10;
    // room size in square feet (double)
    double roomSizeInSquareFeet = 50;
    // recording software name (std::string)
    std::string recordingSoftwareName = "Logic Pro";
    // hourly rental price (float)
    float hourlyRentalPrice = 135.f;
    
    //3 things it can do:
    //    1) record vocals
    void recordVocals(std::string singerName);
    
    //    2) mix audio tracks
    void mixAudioTracks(int numOfTracks);
    
    //    3) export music files
    std::string exportMusicFile(std::string fileName);  // returns exported file name
};
struct Computer
{
    // CPU speed in GHz (double)
    double cpuSpeedInGhz = 4;
    // amount of RAM in Gb (int)
    int amountRamInGb = 128;
    // storage size in Gb (int)
    int storageSizeInGb = 8000;
    // operating system name (std::string)
    std::string operatingSystemName = "MacOS Tahoe";
    // number of USB ports (int)
    int numOfUsbPorts = 8;
    
    //3 things it can do:
    //    1) run audio software
    void runAudioSoftware(std::string softwareName);
    
    //    2) save project files
    void saveProjectFile(std::string projectName);
    
    //    3) process audio plugins
    int processAudioPlugins(int numOfPlugins);  // returns number of processed plugins
};
struct AudioInterface
{
    // number of input channels (int)
    int numOfInputChannels = 26;
    // number of output channels (int)
    int numOfCoutputChannels = 20;
    // sample rate in KHz (double)
    double sampleRateInKhz = 48000;
    // phantom power enabled (bool)
    bool isPhantonPowerEnabled = true;
    // headphone output volume (float)
    float headphoneOutputVolume = 45.5f;
    
    //3 things it can do:
    //    1) convert analog audio to digital audio
    void convertAnalogToDigitalAudio();
    
    //    2) send audio to studio monitors
    void sendAudioToStudioMonitors(float outputVolume);
    
    //    3) connect microphones and instruments
    bool connectMicrophone(std::string microphoneName); // returns true if microphone connected successfully
};
struct StudioMonitors
{
    // speaker size in inches (double)
    double speakerSizeInInches = 10;
    // power outputs in watts (int)
    int powerOutputsInWatts = 1200;
    // frequency response range in Hz (float)
    float frequencyResponseRangeInHz = 250;
    // volume level (float)
    float volumeLevel = 45.f;
    // cabinet width in cm (double)
    double cabinetWidthInCm = 30;
    
    //3 things it can do:
    //    1) play audio playback
    void playAudioPlayback(std::string audioFileName);
    
    //    2) reproduce low frequencies
    void reproduceLowFrequencies();
    
    //    3) monitor a recording session
    void monitorRecordingSession(int sessionDurationInMinutes);
};
struct MidiKeyboard
{
    // number of keys (int)
    int numOfKeys = 88;
    // octave range (int)
    int octaveRange = 7;
    // velocity sensitivity enabled (bool)
    bool isVelocitySensitivityEnabled = true;
    // number of controls knobs (int)
    int numOfControlKnobs = 12;
    // USB connection type (std::string)
    std::string usbConnectionType = "USB-C";
    
    //3 things it can do:
    //    1) send MIDI notes
    void sendMidiNotes(int midiNoteNumber);
    
    //    2) control virtual instruments
    void controlVirtualInstrument(std::string instrumentName);
    
    //    3) adjust plugin parameters
    void adjustPluginParameter(std::string parameterName, float parameterValue);
};
struct Microphone
{
    // microphone type (std::string)
    std::string microphoneType = "Condenser";
    // frequency response range in Hz (float)
    float frequencyResponseRangeInHz = 80;
    // sensitivity level (double)
    double sensitivityLevel = 5;
    // cable lenght in meters (double)
    double cableLenghtInMeters = 2;
    // maximum sound pressure level in dB (int)
    int maximumSoundPressureLevelInDb = 12;
    
    //3 things it can do:
    //    1) capture vocal recordings
    void captureVocalRecording(std::string vocalistName);
    
    //    2) record accoustic instruments
    void recordAcousticInstrument(std::string instrumentName);
    
    //    3) reduce background noise
    bool reduceBackgroundNoise();   // returns true if noise reduction was successful
};
struct MusicStudioComputerSetup
{
    //    1) computer
    Computer computer;
    //    2) audio interface
    AudioInterface audioInterface;
    //    3) studio monitors
    StudioMonitors studioMonitors;
    //    4) MIDI keyboard
    MidiKeyboard midiKeyboard;
    //    5) microphone
    Microphone microphone;
    
    //3 things it can do:
    //    1) record music
    void recordMusic(std::string projectName);
    
    //    2) edit audio track
    void editAudioTrack(std::string trackName);
    
    //    3) play virtual instruments
    void playVirtualInstrument(std::string instrumentName);
};









int main()
{
    std::cout << "good to go!" << std::endl;
}
