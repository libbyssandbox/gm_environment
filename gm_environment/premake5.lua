PROJECT_GENERATOR_VERSION = 3

include("./garrysmod_common/")
CreateWorkspace({name = "environment", abi_compatible = false, path = "projects/"})
	CreateProject({serverside = true, source_path = "src", manual_files = false})
		files({
			"src/**.*"
		})
