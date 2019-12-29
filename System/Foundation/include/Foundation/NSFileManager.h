#import <Foundation/NSObject.h>
#import <Foundation/NSEnumerator.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSPathUtilities.h>
#import <CoreFoundation/CFBase.h>

#define NSFoundationVersionWithFileManagerResourceForkSupport 412

typedef NS_OPTIONS(NSUInteger, NSVolumeEnumerationOptions) {
    NSVolumeEnumerationSkipHiddenVolumes        = 1UL << 1,
    NSVolumeEnumerationProduceFileReferenceURLs = 1UL << 2
};

typedef NS_OPTIONS(NSUInteger, NSDirectoryEnumerationOptions) {
    NSDirectoryEnumerationSkipsSubdirectoryDescendants = 1UL << 0,
    NSDirectoryEnumerationSkipsPackageDescendants      = 1UL << 1,
    NSDirectoryEnumerationSkipsHiddenFiles             = 1UL << 2
};

typedef NS_OPTIONS(NSUInteger, NSFileManagerItemReplacementOptions) {
    NSFileManagerItemReplacementUsingNewMetadataOnly = 1UL << 0,
    NSFileManagerItemReplacementWithoutDeletingBackupItem = 1UL << 1
};

FOUNDATION_EXPORT NSString * const NSUbiquityIdentityDidChangeNotification;
FOUNDATION_EXPORT NSString * const NSFileType;
FOUNDATION_EXPORT NSString * const NSFileTypeDirectory;
FOUNDATION_EXPORT NSString * const NSFileTypeRegular;
FOUNDATION_EXPORT NSString * const NSFileTypeSymbolicLink;
FOUNDATION_EXPORT NSString * const NSFileTypeSocket;
FOUNDATION_EXPORT NSString * const NSFileTypeCharacterSpecial;
FOUNDATION_EXPORT NSString * const NSFileTypeBlockSpecial;
FOUNDATION_EXPORT NSString * const NSFileTypeUnknown;
FOUNDATION_EXPORT NSString * const NSFileSize;
FOUNDATION_EXPORT NSString * const NSFileModificationDate;
FOUNDATION_EXPORT NSString * const NSFileReferenceCount;
FOUNDATION_EXPORT NSString * const NSFileDeviceIdentifier;
FOUNDATION_EXPORT NSString * const NSFileOwnerAccountName;
FOUNDATION_EXPORT NSString * const NSFileGroupOwnerAccountName;
FOUNDATION_EXPORT NSString * const NSFilePosixPermissions;
FOUNDATION_EXPORT NSString * const NSFileSystemNumber;
FOUNDATION_EXPORT NSString * const NSFileSystemFileNumber;
FOUNDATION_EXPORT NSString * const NSFileExtensionHidden;
FOUNDATION_EXPORT NSString * const NSFileHFSCreatorCode;
FOUNDATION_EXPORT NSString * const NSFileHFSTypeCode;
FOUNDATION_EXPORT NSString * const NSFileImmutable;
FOUNDATION_EXPORT NSString * const NSFileAppendOnly;
FOUNDATION_EXPORT NSString * const NSFileCreationDate;
FOUNDATION_EXPORT NSString * const NSFileOwnerAccountID;
FOUNDATION_EXPORT NSString * const NSFileGroupOwnerAccountID;
FOUNDATION_EXPORT NSString * const NSFileBusy;
FOUNDATION_EXPORT NSString * const NSFileProtectionKey;
FOUNDATION_EXPORT NSString * const NSFileProtectionNone;
FOUNDATION_EXPORT NSString * const NSFileProtectionComplete;
FOUNDATION_EXPORT NSString * const NSFileProtectionCompleteUnlessOpen;
FOUNDATION_EXPORT NSString * const NSFileProtectionCompleteUntilFirstUserAuthentication;
FOUNDATION_EXPORT NSString * const NSFileSystemSize;
FOUNDATION_EXPORT NSString * const NSFileSystemFreeSize;
FOUNDATION_EXPORT NSString * const NSFileSystemNodes;
FOUNDATION_EXPORT NSString * const NSFileSystemFreeNodes;

@class NSArray, NSData, NSDate, NSDirectoryEnumerator, NSError, NSNumber, NSFileManager;

@protocol NSFileManagerDelegate <NSObject>
@optional

- (BOOL)fileManager:(NSFileManager *)fileManager shouldCopyItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldCopyItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error copyingItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error copyingItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldMoveItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldMoveItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error movingItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error movingItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldLinkItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldLinkItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error linkingItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error linkingItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldRemoveItemAtPath:(NSString *)path;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldRemoveItemAtURL:(NSURL *)URL;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error removingItemAtPath:(NSString *)path;
- (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error removingItemAtURL:(NSURL *)URL;

@end

@interface NSFileManager : NSObject

+ (NSFileManager *)defaultManager;
- (NSArray *)mountedVolumeURLsIncludingResourceValuesForKeys:(NSArray *)propertyKeys options:(NSVolumeEnumerationOptions)options;
- (NSArray *)contentsOfDirectoryAtURL:(NSURL *)url includingPropertiesForKeys:(NSArray *)keys options:(NSDirectoryEnumerationOptions)mask error:(NSError **)error;
- (NSArray *)URLsForDirectory:(NSSearchPathDirectory)directory inDomains:(NSSearchPathDomainMask)domainMask;
- (NSURL *)URLForDirectory:(NSSearchPathDirectory)directory inDomain:(NSSearchPathDomainMask)domain appropriateForURL:(NSURL *)url create:(BOOL)shouldCreate error:(NSError **)error;
- (BOOL)createDirectoryAtURL:(NSURL *)url withIntermediateDirectories:(BOOL)createIntermediates attributes:(NSDictionary *)attributes error:(NSError **)error;
- (BOOL)createSymbolicLinkAtURL:(NSURL *)url withDestinationURL:(NSURL *)destURL error:(NSError **)error;
- (void)setDelegate:(id)delegate;
- (id)delegate;
- (BOOL)setAttributes:(NSDictionary *)attributes ofItemAtPath:(NSString *)path error:(NSError **)error;
- (BOOL)createDirectoryAtPath:(NSString *)path withIntermediateDirectories:(BOOL)createIntermediates attributes:(NSDictionary *)attributes error:(NSError **)error;
- (NSArray *)contentsOfDirectoryAtPath:(NSString *)path error:(NSError **)error;
- (NSArray *)subpathsOfDirectoryAtPath:(NSString *)path error:(NSError **)error;
- (NSDictionary *)attributesOfItemAtPath:(NSString *)path error:(NSError **)error;
- (NSDictionary *)attributesOfFileSystemForPath:(NSString *)path error:(NSError **)error;
- (BOOL)createSymbolicLinkAtPath:(NSString *)path withDestinationPath:(NSString *)destPath error:(NSError **)error;
- (NSString *)destinationOfSymbolicLinkAtPath:(NSString *)path error:(NSError **)error;
- (BOOL)copyItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error;
- (BOOL)moveItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error;
- (BOOL)linkItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error;
- (BOOL)removeItemAtPath:(NSString *)path error:(NSError **)error;
- (BOOL)copyItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL error:(NSError **)error;
- (BOOL)moveItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL error:(NSError **)error;
- (BOOL)linkItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL error:(NSError **)error;
- (BOOL)removeItemAtURL:(NSURL *)URL error:(NSError **)error;
- (BOOL)trashItemAtURL:(NSURL *)url resultingItemURL:(NSURL **)outResultingURL error:(NSError **)error;
- (NSDictionary *)fileAttributesAtPath:(NSString *)path traverseLink:(BOOL)yorn;
- (BOOL)changeFileAttributes:(NSDictionary *)attributes atPath:(NSString *)path;
- (NSArray *)directoryContentsAtPath:(NSString *)path;
- (NSDictionary *)fileSystemAttributesAtPath:(NSString *)path;
- (NSString *)pathContentOfSymbolicLinkAtPath:(NSString *)path;
- (BOOL)createSymbolicLinkAtPath:(NSString *)path pathContent:(NSString *)otherpath;
- (BOOL)createDirectoryAtPath:(NSString *)path attributes:(NSDictionary *)attributes;
- (NSString *)currentDirectoryPath;
- (BOOL)changeCurrentDirectoryPath:(NSString *)path;
- (BOOL)fileExistsAtPath:(NSString *)path;
- (BOOL)fileExistsAtPath:(NSString *)path isDirectory:(BOOL *)isDirectory;
- (BOOL)isReadableFileAtPath:(NSString *)path;
- (BOOL)isWritableFileAtPath:(NSString *)path;
- (BOOL)isExecutableFileAtPath:(NSString *)path;
- (BOOL)isDeletableFileAtPath:(NSString *)path;
- (BOOL)contentsEqualAtPath:(NSString *)path1 andPath:(NSString *)path2;
- (NSString *)displayNameAtPath:(NSString *)path;
- (NSArray *)componentsToDisplayForPath:(NSString *)path;
- (NSDirectoryEnumerator *)enumeratorAtPath:(NSString *)path;
#if NS_BLOCKS_AVAILABLE
- (NSDirectoryEnumerator *)enumeratorAtURL:(NSURL *)url includingPropertiesForKeys:(NSArray *)keys options:(NSDirectoryEnumerationOptions)mask errorHandler:(BOOL (^)(NSURL *url, NSError *error))handler;
#endif
- (NSArray *)subpathsAtPath:(NSString *)path;
- (NSData *)contentsAtPath:(NSString *)path;
- (BOOL)createFileAtPath:(NSString *)path contents:(NSData *)data attributes:(NSDictionary *)attr;
- (const char *)fileSystemRepresentationWithPath:(NSString *)path NS_RETURNS_INNER_POINTER;
- (NSString *)stringWithFileSystemRepresentation:(const char *)str length:(NSUInteger)len;
- (BOOL)replaceItemAtURL:(NSURL *)originalItemURL withItemAtURL:(NSURL *)newItemURL backupItemName:(NSString *)backupItemName options:(NSFileManagerItemReplacementOptions)options resultingItemURL:(NSURL **)resultingURL error:(NSError **)error;
- (BOOL)setUbiquitous:(BOOL)flag itemAtURL:(NSURL *)url destinationURL:(NSURL *)destinationURL error:(NSError **)error;
- (BOOL)isUbiquitousItemAtURL:(NSURL *)url;
- (BOOL)startDownloadingUbiquitousItemAtURL:(NSURL *)url error:(NSError **)error;
- (BOOL)evictUbiquitousItemAtURL:(NSURL *)url error:(NSError **)error;
- (NSURL *)URLForUbiquityContainerIdentifier:(NSString *)containerIdentifier;
- (NSURL *)URLForPublishingUbiquitousItemAtURL:(NSURL *)url expirationDate:(NSDate **)outDate error:(NSError **)error;
- (id <NSObject, NSCopying, NSCoding>)ubiquityIdentityToken;

@end

@interface NSObject (NSCopyLinkMoveHandler)
- (BOOL)fileManager:(NSFileManager *)fm shouldProceedAfterError:(NSDictionary *)errorInfo;
- (void)fileManager:(NSFileManager *)fm willProcessPath:(NSString *)path;
@end

@interface NSDirectoryEnumerator : NSEnumerator

- (NSDictionary *)fileAttributes;
- (NSDictionary *)directoryAttributes;
- (void)skipDescendents;
- (NSUInteger)level;
- (void)skipDescendants;

@end

@interface NSDictionary (NSFileAttributes)

- (unsigned long long)fileSize;
- (NSDate *)fileModificationDate;
- (NSString *)fileType;
- (NSUInteger)filePosixPermissions;
- (NSString *)fileOwnerAccountName;
- (NSString *)fileGroupOwnerAccountName;
- (NSInteger)fileSystemNumber;
- (NSUInteger)fileSystemFileNumber;
- (BOOL)fileExtensionHidden;
- (OSType)fileHFSCreatorCode;
- (OSType)fileHFSTypeCode;
- (BOOL)fileIsImmutable;
- (BOOL)fileIsAppendOnly;
- (NSDate *)fileCreationDate;
- (NSNumber *)fileOwnerAccountID;
- (NSNumber *)fileGroupOwnerAccountID;

@end
