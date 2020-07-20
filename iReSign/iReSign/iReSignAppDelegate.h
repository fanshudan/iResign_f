

#import <Cocoa/Cocoa.h>
#import "IRTextFieldDrag.h"

@interface iReSignAppDelegate : NSObject <NSApplicationDelegate> {
@private
    NSWindow *__unsafe_unretained window;
    
    NSUserDefaults *defaults;
    
    NSTask *unzipTask;
    NSTask *copyTask;
    NSTask *provisioningTask;
    NSTask *codesignTask;
    NSTask *generateEntitlementsTask;
    NSTask *verifyTask;
    NSTask *zipTask;
    NSString *sourcePath;
    NSString *appPath;
    NSString *frameworksDirPath;
    NSString *frameworkPath;
    NSString *plugInsDirPath;
    NSString *plugInPath;
    NSString *workingPath;
    NSString *appName;
    NSString *fileName;
    
    NSString *entitlementsResult;
    NSString *codesigningResult;
    NSString *verificationResult;
    
    NSMutableArray *targetPaths;
    
    NSMutableArray *frameworks;
    Boolean hasFrameworks;
    
    NSMutableArray *plugIns;
    Boolean hasPlugIns;
    
    IBOutlet IRTextFieldDrag *pathField;
    IBOutlet IRTextFieldDrag *provisioningPathField;
    IBOutlet IRTextFieldDrag *entitlementField;
    IBOutlet IRTextFieldDrag *bundleIDField;
    IBOutlet NSButton    *browseButton;
    IBOutlet NSButton    *provisioningBrowseButton;
    IBOutlet NSButton *entitlementBrowseButton;
    IBOutlet NSButton    *resignButton;
    IBOutlet NSTextField *statusLabel;
    IBOutlet NSProgressIndicator *flurry;
    IBOutlet NSButton *changeBundleIDCheckbox;
    
    IBOutlet NSComboBox *certComboBox;
    NSMutableArray *certComboBoxItems;
    NSTask *certTask;
    NSArray *getCertsResult;
    
}

@property (unsafe_unretained) IBOutlet NSWindow *window;

@property (nonatomic, strong) NSString *workingPath;

- (IBAction)resign:(id)sender;
- (IBAction)browse:(id)sender;
- (IBAction)provisioningBrowse:(id)sender;
- (IBAction)entitlementBrowse:(id)sender;
- (IBAction)changeBundleIDPressed:(id)sender;

- (void)checkUnzip:(NSTimer *)timer;
- (void)checkCopy:(NSTimer *)timer;
- (void)doProvisioning;
- (void)checkProvisioning:(NSTimer *)timer;
- (void)doCodeSigning;
- (void)checkCodesigning:(NSTimer *)timer;
- (void)doVerifySignature;
- (void)checkVerificationProcess:(NSTimer *)timer;
- (void)doZip;
- (void)checkZip:(NSTimer *)timer;
- (void)disableControls;
- (void)enableControls;

@end
