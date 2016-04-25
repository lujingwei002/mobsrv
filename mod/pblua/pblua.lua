module('Pblua', package.seeall)

function import_dir(dir)
    Pblua.mappath('', dir)
    local files = File.listdir(dir)
    for _, file in pairs(files) do
        if file.type == 'file' and string.find(file.name, '.proto$') then
            log('load proto(%s)', file.name)
            Pblua.import(file.name)
        end
    end
end

