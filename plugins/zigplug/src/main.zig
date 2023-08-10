const std = @import("std");
const plugin = @cImport(@cInclude("engine/plugin.h"));

const generalPurposeAllocator = std.heap.GeneralPurposeAllocator(.{}){};
const allocator = &generalPurposeAllocator.allocator;

const ZigPlugin = struct {
    const Self = @This();

    callback: fn (void) void,

    pub fn getPluginName() ![]const u8 {
        return "ZigPlugin";
    }

    pub fn init(self: *Self) !void {
        _ = self;
        std.debug.warn("ZigPlugin init\n", .{});
    }

    pub fn shutdown(self: *Self) !void {
        _ = self;
        std.debug.warn("ZigPlugin shutdown\n", .{});
    }

    pub fn update(self: *Self) !void {
        _ = self;
        std.debug.warn("ZigPlugin update\n", .{});
    }

    pub fn setEventCallback(self: *Self, callback: fn (void) void) !void {
        self.callback = callback;
    }
};

fn createPlugin() *plugin.Plugin {
    var plug: *ZigPlugin = allocator.alloc(ZigPlugin) or return null;
    return plug;
}

fn destroyPlugin(plug: *plugin.Plugin) void {
    try allocator.free(plug);
}
