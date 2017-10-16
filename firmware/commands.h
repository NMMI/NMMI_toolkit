enum class nmmi_command
{
    //=========================================================     general commands

    CMD_PING                    = 0,    ///< Asks for a ping message
    CMD_SET_ZEROS               = 1,    ///< Command for setting the encoders zero position
    CMD_STORE_PARAMS            = 3,    ///< Stores all parameters in memory and
                                        ///  loads them
    CMD_STORE_DEFAULT_PARAMS    = 4,    ///< Store current parameters as factory parameters
    CMD_RESTORE_PARAMS          = 5,    ///< Restore default factory parameters
    CMD_GET_INFO                = 6,    ///< Asks for a string of information about

    CMD_SET_VALUE               = 7,    ///< Not Used
    CMD_GET_VALUE               = 8,    ///< Not Used

    CMD_BOOTLOADER              = 9,    ///< Sets the bootloader modality to update the
                                        ///  firmware
    CMD_INIT_MEM                = 10,   ///< Initialize the memory with the defalut values
    CMD_CALIBRATE               = 11,   ///< Starts the stiffness calibration of the qbMove
                                        ///  or the hand closure and opening calibration
    CMD_GET_PARAM_LIST          = 12,   ///< Command to get the parameters list or to set
                                        ///  a defined value chosen by the use
    CMD_HAND_CALIBRATE          = 13,   ///< Starts a series of opening and closures of the hand
    
    //=========================================================     qbcommands

    CMD_ACTIVATE                = 128,  ///< Command for activating/deactivating
                                        ///  the device
    CMD_GET_ACTIVATE            = 129,  ///< Command for getting device activation
                                        ///  state
    CMD_SET_INPUTS              = 130,  ///< Command for setting reference inputs
    CMD_GET_INPUTS              = 131,  ///< Command for getting reference inputs
    CMD_GET_MEASUREMENTS        = 132,  ///< Command for asking device's
                                        ///  position measurements
    CMD_GET_CURRENTS            = 133,  ///< Command for asking device's
                                        ///  current measurements
    CMD_GET_CURR_AND_MEAS       = 134,  ///< Command for asking device's
                                        ///  measurements and currents
    CMD_SET_POS_STIFF           = 135,  ///< Not used in the softhand firmware
    CMD_GET_EMG                 = 136,  ///< Command for asking device's emg sensors 
                                        ///  measurements
    CMD_GET_VELOCITIES          = 137,  ///< Command for asking device's
                                        ///  velocity measurements
    CMD_GET_COUNTERS            = 138,  ///< Command for asking device's counters
                                        ///  (mostly used for debugging sent commands)
    CMD_GET_ACCEL               = 139,  ///< Command for asking device's
                                        ///  acceleration measurements
    CMD_GET_CURR_DIFF           = 140,  ///< Command for asking device's 
                                        ///  current difference between a measured
                                        ///  one and an estimated one (Only for SoftHand)
    CMD_SET_CURR_DIFF           = 141,  ///< Command used to set current difference modality
                                        ///  (Only for Cuff device)
    CMD_SET_CUFF_INPUTS         = 142,  ///< Command used to set Cuff device inputs 
                                        ///  (Only for Cuff device)
    CMD_SET_WATCHDOG            = 143,  ///< Command for setting watchdog timer
                                        ///  or disable it
    CMD_SET_BAUDRATE            = 144,  ///< Command for setting baudrate
                                        ///  of communication
    CMD_EXT_DRIVE               = 145,  ///< Command to set the actual measurements as inputs
                                        ///  to another device (Only for Armslider device)
    CMD_GET_JOYSTICK            = 146,   ///< Command to get the joystick measurements (Only 
                                        ///  for devices driven by a joystick)

    //=========================================================     W_FYD
    
    CMD_GET_IR            	= 147,  ///< Command for asking ir readings (W-FYD)
    CMD_SET_SERVO           	= 148,  ///< Command for setting servo position (W-FYD)
    CMD_GET_SERVO           	= 149,  ///< Command for asking servo position (W-FYD)
    CMD_GET_FORCE           	= 150,  ///< Command for asking force measures (W-FYD)
    CMD_GET_DUTY_CY_MAX     	= 151,   ///< Command for setting the max dc (W-FYD)

    //=========================================================     IMU
    
    CMD_GET_N_IMU           	= 160,  // Get number of IMUs connected to board
    CMD_GET_IMU_READINGS    	= 161  // Retrieve accelerometers, gyroscopes and magnetometers readings
    
};