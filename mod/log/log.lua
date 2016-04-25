module('Log', package.seeall)

function log_(tag, format, ...)
    Log.log(string.format('[%12s]'..format, tag, ...))
end

function error_(tag, format, ...)
    Log.error(string.format('[%s]'..format, tag, ...))
end

function msg_(tag, format, ...)
    Log.msg(string.format('[%s]'..format, tag, ...))
end

function warn_(tag, format, ...)
    Log.warn(string.format('[%s]'..format, tag, ...))
end

