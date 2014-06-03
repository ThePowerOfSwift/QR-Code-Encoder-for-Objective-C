

#import "DataMatrix.h"


@implementation DataMatrix

- (id)initWith:(int)dimension {
    self = [super init];
    if (self) {
        dim = dimension;
        data = (bool**)malloc(sizeof(bool*) * dim);
        for (int y=0; y<self->dim; y++) {
            data[y] = (bool*)malloc(sizeof(bool) * dim);
            if (data[y]==NULL) {
                NSLog(@"null!");
            }
        }
    }
    return self;
}

- (int)dimension {
    return dim;
}

- (void)set:(bool)value x:(int)x y:(int)y {
    data[y][x] = value;
}

- (bool)valueAt:(int)x y:(int)y {
    return data[y][x];
}

- (NSString*)toString {
    NSString* string = [NSString string];
    for (int y = 0; y < dim; y++) {
        for (int x = 0; x < dim; x++) {
            bool value = data[y][x];
            string = [string stringByAppendingFormat:@"%d", value];
        }
        string = [string stringByAppendingString:@"\n"];
    }
    return string;
}

- (void)dealloc {
    for (int y = 0; y < dim; y++) {
        free(data[y]);
    }
    free(data);
}

@end
