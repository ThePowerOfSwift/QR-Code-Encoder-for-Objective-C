

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CommonCrypto/CommonCryptor.h>
#import "DataMatrix.h"

const static int QR_ECLEVEL_AUTO =  0;
extern const int QR_ECLEVEL_H;
extern const int QR_ECLEVEL_M;
extern const int QR_ECLEVEL_L;
extern const int QR_ECLEVEL_Q;

const static int QR_VERSION_AUTO =  -1;

const static int BITS_PER_BYTE =    8;
const static int BYTES_PER_PIXEL =  4;

const static unsigned char WHITE =  0xff;

@interface QREncoder : NSObject {
    
}

+ (DataMatrix*)encodeWithECLevel:(int)ecLevel version:(int)version string:(NSString *)string AESPassphrase:(NSString*)AESPassphrase;

+ (DataMatrix*)encodeWithECLevel:(int)ecLevel version:(int)version string:(NSString*)string;

+ (UIImage*)renderDataMatrix:(DataMatrix*)matrix imageDimension:(int)imageDimension;

+ (UIImage*)QRCodeImageFromString:(NSString *)string imageSize:(int)size;

@end

void FLProviderReleaseData(void *info, const void *data, size_t size);
